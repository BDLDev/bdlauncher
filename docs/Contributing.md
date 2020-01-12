# Contributing

When contributing to this repository, please first discuss the change you wish to make via issue, email, or any other method with the owners of this repository before making a change.

Please note we have a code of conduct, please follow it in all your interactions with the project.

## Pull Request Process

1. Use dev branch
2. Format code before commit

## Coding style

### Format

Use clang-format

1. Install clang-format clang tool. Probably, any version will be ok, but the newer the better.
2. You'll need to integrate git and clang-format.
   * For that, you will need to download git-clang-format from here or here.
   * Read it to check for nastiness.
   * Put it somewhere in your path (e.g. ~/bin or /usr/local/bin) and ensure   that it is executable (chmod +x).
3. Now, step into your local clone of repository:
   * cd `.git/hooks`
   * If you previously did not have a pre-commit hook:
     * cp pre-commit.sample pre-commit && chmod +x pre-commit
   * Open pre-commit with your favourite text editor, and append before the last block, here is how the end should look:
     ```
     # format everything
     res=$(git clang-format --diff | wc -l)
     if [ $res -ne 1 ]
     then
     	git clang-format
     	echo "Commit did not match clang-format"
     	exit 1;
     fi

     # If there are whitespace errors, print the offending file names and fail.
     exec git diff-index --check --cached $against --
     ```

### Markdown Formatting

The BDLauncher project use [Github Flavored Markdown](https://github.github.com/gfm/).

#### Link

* Prefer to use relative link insteads of absolute link
* Use explicit &lt;br/&gt; insteads of invisible character
* Prefer to use table for commands description
