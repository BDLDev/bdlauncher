#include <elf.h>
#include <string>
#include <vector>
#include <list>
#include <dirent.h>
#include <sys/stat.h>
#include <unordered_map>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <queue>
using std::string, std::vector, std::list, std::unordered_map, std::priority_queue;
struct TopoDepSolver {
  struct Node {
    string name;
    string path;
    int version    = 0;
    int load_prio  = 50;
    int topo_indeg = 0;
    vector<struct Node *> topo_out;
    struct DepDetail {
      string name;
      int version;
    };
    vector<DepDetail> deps;
    bool operator<(const Node &c) { return load_prio < c.load_prio; }
  };
  unordered_map<string, Node> nodes;
  string getMetaData(const string &fname) {
    Elf64_Ehdr ehdr;
    string rv = "wtf";
    int fd    = open(fname.c_str(), O_RDONLY);
    if (fd < 0) {
      perror(fname.c_str());
      exit(1);
    }
    if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr)) {
      perror(("broken ehdr " + fname).c_str());
      exit(1);
    }
    auto shoff  = ehdr.e_shoff;
    auto shnum  = ehdr.e_shnum;
    auto strtab = shoff + ehdr.e_shstrndx * ehdr.e_shentsize;
    Elf64_Shdr str_s;
    pread(fd, &str_s, sizeof(str_s), strtab);
    char *buff = (char *) malloc(str_s.sh_size);
    pread(fd, buff, str_s.sh_size, str_s.sh_offset);
    // printf(buff);
    for (int i = 0; i < shnum; shoff += ehdr.e_shentsize, ++i) {
      Elf64_Shdr shdr;
      pread(fd, &shdr, sizeof(shdr), shoff);
      // printf("%s\n",buff+shdr.sh_name);
      string secname = buff + shdr.sh_name;
      if (secname == "meta") {
        char *buff2 = (char *) malloc(shdr.sh_size);
        pread(fd, buff2, shdr.sh_size, shdr.sh_offset);
        rv = buff2;
        free(buff2);
      }
    }
    close(fd);
    free(buff);
    if (rv == "wtf") {
      printf("cannot find section 'meta' in %s\n", fname.c_str());
      exit(1);
    }
    return rv;
  }
  void split_string(const string &s, vector<string> &v, char c) {
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2) {
      v.push_back(s.substr(pos1, pos2 - pos1)); //
      pos1 = pos2 + 1;
      pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length()) v.push_back(string(s.data() + pos1, s.size() - pos1));
  }
  Node getNode(const string &meta) {
    Node rv;
    vector<string> kv;
    split_string(meta, kv, '\n');
    for (auto &i : kv) {
      auto pos = i.find(':');
      if (pos == string::npos) continue;
      string key = i.substr(0, pos);
      string val = i.substr(pos + 1);
      // printf("key %s val %s\n",key.c_str(),val.c_str());
      if (key == "name") { rv.name = val; }
      if (key == "prio") { rv.load_prio = atoi(val.c_str()); }
      if (key == "version") { rv.version = atoi(val.c_str()); }
      if (key == "depend") {
        vector<string> deps;
        split_string(val, deps, ',');
        for (auto &j : deps) {
          auto pos2 = j.find('@');
          if (pos2 != string::npos) {
            rv.deps.push_back({j.substr(0, pos2), atoi(j.substr(pos2 + 1).c_str())});
          } else {
            rv.deps.push_back({j, 0});
          }
        }
      }
    }
    return rv;
  }
  list<string> topoSort() {
    list<string> rv;
    priority_queue<Node *> que;
    for (auto &[mname, i] : nodes) {
      if (i.topo_indeg == 0) que.push(&i);
    }
    while (!que.empty()) {
      Node &i = *que.top();
      que.pop();
      rv.push_back(i.path);
      for (Node *out : i.topo_out) {
        out->topo_indeg--;
        if (out->topo_indeg == 0) que.push(out);
      }
    }
    if (rv.size() != nodes.size()) {
      printf("ERROR: unsolved dependency,loop dependency detected???\n");
      exit(1);
    }
    return rv;
  }
  list<string> solve(vector<string> list) {
    for (auto &i : list) {
      auto &&node = getNode(getMetaData(i));
      node.path   = i;
      nodes.insert({node.name, node});
    }
    // step 1.check dep
    for (auto &[mname, i] : nodes) {
      for (auto &[name, ver] : i.deps) {
        auto it = nodes.find(name);
        if (it == nodes.end()) {
          printf("ERROR : mod %s requires %s,but cant found it!\n", mname.c_str(), name.c_str());
          exit(1);
        }
        if (it->second.version < ver) {
          printf(
              "ERROR : mod %s requires %s(Version %d),but we have version %d!\n", mname.c_str(), name.c_str(), ver,
              it->second.version);
          exit(1);
        }
      }
    }
    // step 2.build edges
    for (auto &[mname, i] : nodes) {
      for (auto &[name, ver] : i.deps) { nodes[name].topo_out.push_back(&i); }
      i.topo_indeg = i.deps.size();
    }
    // step 3.do topoSort
    return topoSort();
  }
  list<string> loadall() {
    DIR *dp = opendir("mods");
    if (!dp) {
      perror("opendir mod/");
      exit(1);
    }
    struct dirent *entry;
    vector<string> modlist;
    while ((entry = readdir(dp)) != NULL) {
      if (entry->d_type & DT_REG) {
        string name = entry->d_name;
        if (name.find(".mod") == name.length() - 4) { modlist.push_back("mods/" + name); }
      }
    }
    closedir(dp);
    return solve(modlist);
  }
};
list<string> solveAll() {
  TopoDepSolver sv;
  return sv.loadall();
}