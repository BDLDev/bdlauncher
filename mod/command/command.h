#include <MC.h>
#include <cmdhelper.h>

#include <type_traits>
#include <string_view>
#include <string>
#include <vector>
#include <memory>
#include <limits>

/**
 * @brief Custom Command Mod
 *
 * Use codegen for command register
 */
namespace BDL::CustomCommand {

/**
 * \defgroup Interface API Interface
 * @{
 */

/**
 * @brief Custom Command Context
 *
 * Used for codegen
 */
class CustomCommandContext {
  ::CommandOrigin const *origin;
  ::CommandOutput *output;

  CustomCommandContext(CustomCommandContext const &) = delete;
  CustomCommandContext(CustomCommandContext &&)      = delete;

protected:
  /**
   * @brief PLEASE JUST CALL IT IN YOUR CONSTRUCTOR
   *
   * @param origin CommandOrigin
   * @param output CommandOutput
   */
  CustomCommandContext(CommandOrigin const &origin, CommandOutput &output) noexcept
      : origin(&origin), output(&output) {}

  // TODO: add more interface
};

/**
 * @brief Dynamic enum, can be changed in any time.
 *
 * @tparam Derived The real DynEnum class
 */
template <typename Derived> class CustomDynEnum {
  std::string_view value;

protected:
  /**
   * @brief Construct a new Custom Dyn Enum object
   *
   * @param value The enum value
   */
  CustomDynEnum(std::string_view value) : value(value) {}

public:
  /**
   * @brief get value
   *
   * @return std::string_view
   */
  inline operator std::string_view() noexcept { return value; };
};

/**
 * @brief Parameter type proxy
 *
 * @tparam RealType
 */
template <typename RealType> class CommandParameterProxy;

class CustomCommandRegistry;

/**
 * @brief Dynamic Enum Controller
 *
 * @tparam DynEnum The target
 */
template <typename DynEnum> class CustomDynEnumHandle {
  static_assert(std::is_base_of_v<CustomDynEnum<DynEnum>, DynEnum>);
  friend class CustomCommandRegistry;
  CustomCommandRegistry *registry;

  CustomDynEnumHandle(CustomCommandRegistry *registry) noexcept : registry(registry) {}

public:
  /**
   * @brief add value to dynamic enum
   *
   * @param value the value
   */
  void addValue(std::string_view value) noexcept; // TODO: implement

  /**
   * @brief del value to dynamic enum
   *
   * @param value
   */
  void delValue(std::string_view value) noexcept; // TODO: implement

  /**
   * @brief clear dynamic enum
   */
  void clear() noexcept; // TODO: implement
};

/**
 * @brief The registry
 */
class CustomCommandRegistry {
  class Application {
    virtual void apply(::CommandRegistry *registry) = 0;
    friend class CustomCommandRegistry;

  public:
    virtual ~Application() {}
  };

  template <typename DynEnum> friend class CustomDynEnumHandle;
  ::CommandRegistry *vanilla;
  std::vector<std::unique_ptr<Application>> applications;

public:
  /**
   * @brief Enum registering application
   *
   * @tparam Enum Target enum
   */
  template <typename Enum> class EnumApplication : public Application {
    std::string name;
    inline EnumApplication(std::string_view name) : name(name) {}
    EnumApplication(EnumApplication const &) = delete;
    EnumApplication(EnumApplication &&)      = delete;
    virtual void apply(::CommandRegistry *registry) override; // TODO

  public:
    /**
     * @brief Add value to enum
     *
     * @param name name
     * @param value value
     */
    void addValue(std::string_view name, Enum value); // TODO
  };

  /**
   * @brief Dynamic Enum Application
   *
   * @tparam DynEnum The target
   */
  template <typename DynEnum> class CustomDynEnumApplication : public Application {
    static_assert(std::is_base_of_v<CustomDynEnum<DynEnum>, DynEnum>);
    CustomDynEnumApplication(CustomDynEnumApplication const &) = delete;
    CustomDynEnumApplication(CustomDynEnumApplication &&)      = delete;
    virtual void apply(::CommandRegistry *registry) override; // TODO
  };

  /**
   * @brief Command registering application
   *
   * @tparam Desc The command description class
   */
  template <typename Desc> class CommandApplication : public Application {
    std::vector<::CommandRegistry::Overload> overloads;

    CommandApplication(CommandApplication const &)     = delete;
    CommandApplication(CommandApplication &&) noexcept = delete;
    virtual void apply(::CommandRegistry *registry) override;

  public:
    /** @brief Construct a new Command Application object */
    CommandApplication() noexcept {}
    /**
     * @brief Command overload registering application
     *
     * @tparam Impl Command host class
     */
    template <typename Host> class OverloadApplication {
      friend class CommandApplication;
      CommandApplication *parent;
      std::vector<CommandParameterData> params;
      inline OverloadApplication(CommandApplication *parent) : parent(parent){};
      operator CommandRegistry::Overload();

    public:
      /**
       * @brief Add parameter definition to overload
       *
       * @tparam Type The parameter type
       * @param name The parameter name
       * @param optional Optional flag
       */
      template <typename Type> void addParameter(std::string_view name, bool optional, size_t offset);

      /**
       * @brief Destroy the Overload Application object: commit to overload vector
       */
      ~OverloadApplication() { parent->overloads.emplace_back((CommandRegistry::Overload) * this); }
    };

    /**
     * @brief Register command overload
     *
     * @tparam Host Command host class
     * @return OverloadApplication<Host> Command overload registering application
     */
    template <typename Host> OverloadApplication<Host> registerOverload() { return {this}; };

    /** @brief Destroy the Command Application object */
    ~CommandApplication() {}
  };

  /**
   * @brief Get the Instance object
   *
   * @return CustomCommandRegistry& instance
   */
  static CustomCommandRegistry &getInstance(); // Note: implemented in cpp

  /**
   * @brief Starting registering
   *
   * Should not be call in user land
   *
   * @param registry Vanilla Command Registry
   */
  void startRegister(::CommandRegistry *registry);

  /**
   * @brief Register dynamic enum
   *
   * @tparam DynEnum Target dynamic enum type
   * @return CustomDynEnumHandle<DynEnum> The dynamic handle
   */
  template <typename DynEnum>
  std::enable_if_t<std::is_base_of_v<CustomDynEnum<DynEnum>, CustomDynEnumHandle<DynEnum>>> registerDynEnum() {
    auto obj = std::make_unique<CustomDynEnumApplication<DynEnum>>();
    applications.push_back(obj);
    return {this};
  }

  /**
   * @brief Register static enum
   *
   * @tparam Enum Target static enum type
   * @param name Target enum name
   * @return EnumApplication<Enum> Enum registering application
   */
  template <typename Enum> EnumApplication<Enum> &registerEnum(std::string_view name) {
    auto obj = std::make_unique<EnumApplication<Enum>>(name);
    auto ret = obj.get();
    applications.push_back(obj);
    return *ret;
  }

  /**
   * @brief Register command
   *
   * @tparam Desc CommandDescription type
   * @return CommandApplication<Desc> Command registering application
   */
  template <typename Desc> CommandApplication<Desc> &registerCommand() {
    auto obj = std::make_unique<CommandApplication<Desc>>();
    auto ret = obj.get();
    applications.emplace_back(std::move(obj));
    return *ret;
  }
};

/** @} */

/**
 * \defgroup Private Private implemention details
 * @{
 */

template <typename Desc> void CustomCommandRegistry::CommandApplication<Desc>::apply(::CommandRegistry *registry) {
  std::string name = Desc::name;
  registry->registerCommand(name, Desc::description, Desc::permission, (::CommandFlag) 0, (::CommandFlag) 0);
  auto signature       = registry->findCommand(name);
  signature->overloads = std::move(overloads);
  for (auto &overload : signature->overloads) registry->registerOverloadInternal(*signature, overload);
}

template <typename Desc>
template <typename Host>
CustomCommandRegistry::CommandApplication<Desc>::OverloadApplication<Host>::operator CommandRegistry::Overload() {
  CommandRegistry::Overload ret{
      {1, std::numeric_limits<int>::max()},
      +[]() -> std::unique_ptr<::Command> { return std::make_unique<Host>(); },
  };
  ret.params = std::move(params);
  return ret;
}

template <typename Desc>
template <typename Host>
template <typename Type>
void CustomCommandRegistry::CommandApplication<Desc>::OverloadApplication<Host>::addParameter(
    std::string_view name, bool optional, size_t offset) {
  CommandParameterData param{
      CommandParameterProxy<Type>::tid,
      CommandParameterProxy<Type>::parser,
      name,
      CommandParameterProxy<Type>::type,
      CommandParameterProxy<Type>::desc,
      offset,
      !optional,
      0,
  };
  params.emplace_back(param);
}

void CustomCommandRegistry::startRegister(::CommandRegistry *registry) {
  for (auto &application : applications) { application->apply(registry); }
  applications.clear();
}

/** @} */

} // namespace BDL::CustomCommand