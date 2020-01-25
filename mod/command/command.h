#pragma once
#include <MC.h>
#include <cmdhelper.h>
#include <logger.h>
#include <magic.h>

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
  ::CommandOrigin const &origin;
  ::CommandOutput &output;

  CustomCommandContext(CustomCommandContext const &) = delete;
  CustomCommandContext(CustomCommandContext &&)      = delete;

protected:
  /**
   * @brief PLEASE JUST CALL IT IN YOUR CONSTRUCTOR
   *
   * @param origin CommandOrigin
   * @param output CommandOutput
   */
  CustomCommandContext(CommandOrigin const &origin, CommandOutput &output) noexcept : origin(origin), output(output) {}

  CommandOrigin const &getOrigin() const { return origin; }
  CommandOutput &getOutput() { return output; }
};

/**
 * @brief Dynamic enum, can be changed in any time.
 *
 * @tparam Derived The real DynEnum class
 */
template <typename Derived> class CustomDynEnum {
  std::string value;

protected:
  /**
   * @brief Construct a new Custom Dyn Enum object
   *
   * @param value The enum value
   */
  CustomDynEnum(std::string value) : value(value) {}

public:
  /**
   * @brief Get the value
   *
   * @return std::string const& value
   */
  inline operator std::string const &() const noexcept { return value; };

  /**
   * @brief Get c string
   *
   * @return char const* cstring
   */
  char const *c_str() const noexcept { return value.c_str(); }
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
  template <typename Return, typename... Params> class Application {
    virtual Return apply(Params... registry) = 0;
    friend class CustomCommandRegistry;

  public:
    virtual ~Application() {}
  };

  template <typename Return, typename... Params> struct ApplicationArray {
    std::vector<Application<Return, Params...> *> embed;

    ApplicationArray()                         = default;
    ApplicationArray(ApplicationArray const &) = delete;
    ApplicationArray(ApplicationArray &&)      = delete;

    inline auto begin() noexcept { return embed.begin(); }
    inline auto end() noexcept { return embed.end(); }
    inline void clear() {
      for (auto p : embed) delete p;
      embed.clear();
    }

    ~ApplicationArray() { clear(); }

    template <typename Target, typename... ConsParams> inline Target &append(ConsParams... cons) {
      Target *ret = new Target(std::forward<ConsParams>(cons)...);
      embed.emplace_back(ret);
      return *ret;
    }
  };

  template <typename DynEnum> friend class CustomDynEnumHandle;
  ::CommandRegistry *vanilla;
  ApplicationArray<void, ::CommandRegistry *> applications;

public:
  /**
   * @brief Enum registering application
   *
   * @tparam Enum Target enum
   */
  template <typename Enum> class EnumApplication : public Application<void, ::CommandRegistry *> {
    friend class CustomCommandRegistry;
    inline EnumApplication() {}

    std::vector<std::pair<std::string, Enum>> values;

    EnumApplication(EnumApplication const &) = delete;
    EnumApplication(EnumApplication &&)      = delete;
    virtual void apply(::CommandRegistry *registry) override;

  public:
    /**
     * @brief Add value to enum
     *
     * @param name name
     * @param value value
     */
    void addValue(std::string_view name, Enum value) noexcept { values.emplace_back(name, value); }
  };

  /**
   * @brief Dynamic Enum Application
   *
   * @tparam DynEnum The target
   */
  template <typename DynEnum> class CustomDynEnumApplication : public Application<void, ::CommandRegistry *> {
    static_assert(std::is_base_of_v<CustomDynEnum<DynEnum>, DynEnum>);
    template <typename Return, typename... Params> friend class ApplicationArray;
    std::vector<std::string> values;
    CustomDynEnumApplication(CustomDynEnumApplication const &) = delete;
    CustomDynEnumApplication(CustomDynEnumApplication &&)      = delete;
    virtual void apply(::CommandRegistry *registry) override; // TODO
    CustomDynEnumApplication(std::initializer_list<std::string> values) : values(values) {}
  };

  /**
   * @brief Command registering application
   *
   * @tparam Desc The command description class
   */
  template <typename Desc> class CommandApplication : public Application<void, ::CommandRegistry *> {
    CommandApplication(CommandApplication const &)     = delete;
    CommandApplication(CommandApplication &&) noexcept = delete;
    ApplicationArray<::CommandRegistry::Overload> overload_applications;
    virtual void apply(::CommandRegistry *registry) override;

  public:
    /** @brief Construct a new Command Application object */
    CommandApplication() noexcept {}
    /**
     * @brief Command overload registering application
     *
     * @tparam Impl Command host class
     */
    template <typename Host> class OverloadApplication : public Application<::CommandRegistry::Overload> {
      friend class CommandApplication;
      virtual ::CommandRegistry::Overload apply() override;
      ApplicationArray<::CommandParameterData> param_applications;

    public:
      template <typename Type> struct ParameterApplication : Application<::CommandParameterData> {
        char const *name;
        bool optional;
        size_t offset;

        ParameterApplication(char const *name, bool optional, size_t offset)
            : name(name), optional(optional), offset(offset) {}

        virtual ::CommandParameterData apply() override;
      };

      /**
       * @brief Add parameter definition to overload
       *
       * @tparam Type The parameter type
       * @param name The parameter name
       * @param optional Optional flag
       */
      template <typename Type> void addParameter(char const *name, bool optional, size_t offset) {
        param_applications.append<ParameterApplication<Type>>(name, optional, offset);
      }
    };

    /**
     * @brief Register command overload
     *
     * @tparam Host Command host class
     * @return OverloadApplication<Host> Command overload registering application
     */
    template <typename Host> OverloadApplication<Host> &registerOverload() {
      return overload_applications.append<OverloadApplication<Host>>();
    };
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
  template <typename DynEnum> std::enable_if_t<std::is_base_of_v<CustomDynEnum<DynEnum>, DynEnum>> registerDynEnum() {
    applications.append<CustomDynEnumApplication<DynEnum>>(DynEnum::initial);
  }

  /**
   * @brief Register static enum
   *
   * @tparam Enum Target static enum type
   * @return EnumApplication<Enum> Enum registering application
   */
  template <typename Enum> EnumApplication<Enum> &registerEnum() {
    return applications.append<EnumApplication<Enum>>();
  }

  /**
   * @brief Register command
   *
   * @tparam Desc CommandDescription type
   * @return CommandApplication<Desc> Command registering application
   */
  template <typename Desc> CommandApplication<Desc> &registerCommand() {
    return applications.append<CommandApplication<Desc>>();
  }
};

template <typename Type> using mandatory = Type const &;

template <typename Type> using optional = Type const &;

using enum_initial_list = std::initializer_list<std::string>;
using alias_list        = std::initializer_list<std::string>;

using command_register_function = void;

/** @} */

/**
 * \defgroup Private Private implemention details
 * @{
 */

inline void CustomCommandRegistry::startRegister(::CommandRegistry *registry) {
  for (auto &application : applications) application->apply(registry);
  applications.clear();
}

template <typename DynEnum>
void CustomCommandRegistry::CustomDynEnumApplication<DynEnum>::apply(::CommandRegistry *registry) {
  std::string name = DynEnum::name;
  registry->addSoftEnum(name, values);
}

template <typename Enum> void CustomCommandRegistry::EnumApplication<Enum>::apply(::CommandRegistry *registry) {
  std::string enum_name = CommandParameterProxy<Enum>::enum_name;
  registry->addEnumValues<Enum>(enum_name, values);
}

template <typename T> using has_aliases_t = decltype(T::aliases);
template <typename T> using has_aliases   = is_detected<has_aliases_t, T>;

template <typename Desc> void CustomCommandRegistry::CommandApplication<Desc>::apply(::CommandRegistry *registry) {
  std::string name = Desc::cmd_name;
  do_log("register command %s", name.c_str());
  registry->registerCommand(name, Desc::description, Desc::permission, (::CommandFlag) 0, (::CommandFlag) 0);
  auto signature = registry->findCommand(name);
  if constexpr (has_aliases<Desc>::value)
    for (auto &alias : Desc::aliases) registry->registerAlias(name, alias);
  for (auto &overload : overload_applications) {
    signature->overloads.emplace_back(overload->apply());
    registry->registerOverloadInternal(*signature, *signature->overloads.rbegin());
  }
  overload_applications.clear();
}

template <typename Desc>
template <typename Host>
::CommandRegistry::Overload CustomCommandRegistry::CommandApplication<Desc>::OverloadApplication<Host>::apply() {
  ::CommandRegistry::Overload ret{
      {0, std::numeric_limits<int>::max()},
      +[]() -> std::unique_ptr<::Command> { return std::make_unique<Host>(); },
  };
  for (auto &param : param_applications) ret.params.emplace_back(param->apply());
  param_applications.clear();
  return ret;
}

template <typename Desc>
template <typename Host>
template <typename Type>
::CommandParameterData
CustomCommandRegistry::CommandApplication<Desc>::OverloadApplication<Host>::ParameterApplication<Type>::apply() {
  if constexpr (CommandParameterProxy<Type>::type == CommandParameterDataType::SOFT_ENUM)
    return {
        CommandParameterProxy<Type>::fetch_tid(),
        &::CommandRegistry::parse<std::string>,
        name,
        CommandParameterDataType::SOFT_ENUM,
        Type::name,
        (int) offset,
        optional,
        -1,
    };
  else
    return {
        CommandParameterProxy<Type>::fetch_tid(),
        CommandParameterProxy<Type>::parser,
        name,
        CommandParameterProxy<Type>::type,
        nullptr,
        (int) offset,
        optional,
        -1,
    };
}

/** @} */

} // namespace BDL::CustomCommand
