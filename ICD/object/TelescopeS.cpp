// -*- C++ -*-
/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v3.1.3
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       https://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     https://www.dre.vanderbilt.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// /alma/ACS-2025APR/TAO/ACE_wrappers/build/linux/TAO/TAO_IDL/be/be_codegen.cpp:631

#ifndef _TAO_IDL__TMP__TELESCOPES_CPP_
#define _TAO_IDL__TMP__TELESCOPES_CPP_


#include "TelescopeS.h"
#include "tao/PortableServer/Operation_Table_Perfect_Hash.h"
#include "tao/PortableServer/Upcall_Command.h"
#include "tao/PortableServer/Upcall_Wrapper.h"
#include "tao/TAO_Server_Request.h"
#include "tao/ORB_Core.h"
#include "tao/Profile.h"
#include "tao/Stub.h"
#include "tao/IFR_Client_Adapter.h"
#include "tao/Object_T.h"
#include "tao/AnyTypeCode/TypeCode.h"
#include "tao/AnyTypeCode/DynamicC.h"
#include "tao/CDR.h"
#include "tao/operation_details.h"
#include "tao/PortableInterceptor.h"
#include "ace/Dynamic_Service.h"
#include "ace/Malloc_Allocator.h"
#include "cstring"
// TAO_IDL - Generated from
// /alma/ACS-2025APR/TAO/ACE_wrappers/build/linux/TAO/TAO_IDL/be/be_interface.cpp:1853

class TAO_TELESCOPE_MODULE_Telescope_Perfect_Hash_OpTable
  : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len) override;

public:
  const TAO_operation_db_entry * lookup (const char *str, unsigned int len) override;
};

/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: ace_gperf -m -M -J -c -C -D -E -T -f 0 -F 0,0 -a -o -t -p -K opname -L C++ -Z TAO_TELESCOPE_MODULE_Telescope_Perfect_Hash_OpTable -N lookup */

unsigned int
TAO_TELESCOPE_MODULE_Telescope_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static constexpr unsigned char asso_values[] =
    {
     24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
     24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
     24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
     24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
     24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
     24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
     24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
     24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
     24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
     24, 24, 24, 24, 24,  0, 24,  0, 24, 24,
      0,  0, 24,  5, 24, 24, 24, 24, 24,  0,
      0,  0, 24, 24, 24, 24,  5, 24, 24, 24,
     24, 24, 24, 24, 24, 24, 24, 24,
    };
  return len + asso_values[static_cast<int>(str[len - 1])] + asso_values[static_cast<int>(str[0])];
}

const TAO_operation_db_entry *
TAO_TELESCOPE_MODULE_Telescope_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 10,
      MIN_WORD_LENGTH = 5,
      MAX_WORD_LENGTH = 19,
      MIN_HASH_VALUE = 5,
      MAX_HASH_VALUE = 23,
      HASH_VALUE_RANGE = 19,
      DUPLICATES = 0,
      WORDLIST_SIZE = 15
    };

  static const TAO_operation_db_entry wordlist[] =
    {
      {"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
      {"_is_a", std::addressof(TAO_ServantBase::_is_a_thru_poa_skel), nullptr},
      {"moveTo", std::addressof(POA_TELESCOPE_MODULE::Telescope::moveTo_skel), nullptr},
      {"observe", std::addressof(POA_TELESCOPE_MODULE::Telescope::observe_skel), nullptr},
      {"",0,0},
      {"_get_name", std::addressof(POA_ACS::ACSComponent::_get_name_skel), 0},
      {"_interface", std::addressof(TAO_ServantBase::_interface_skel), nullptr},
      {"",0,0},{"",0,0},{"",0,0},
      {"_repository_id", std::addressof(TAO_ServantBase::_repository_id_thru_poa_skel), nullptr},
      {"_component", std::addressof(TAO_ServantBase::_component_thru_poa_skel), nullptr},
      {"",0,0},{"",0,0},
      {"_non_existent", std::addressof(TAO_ServantBase::_non_existent_thru_poa_skel), nullptr},
      {"_get_componentState", std::addressof(POA_ACS::ACSComponent::_get_componentState_skel), 0},
      {"",0,0},{"",0,0},{"",0,0},
      {"getCurrentPosition", std::addressof(POA_TELESCOPE_MODULE::Telescope::getCurrentPosition_skel), nullptr},
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int const key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          const char *s = wordlist[key].opname;

          if (*str == *s && !ACE_OS::strncmp (str + 1, s + 1, len - 1))
            return &wordlist[key];
        }
    }
  return 0;
}

static TAO_TELESCOPE_MODULE_Telescope_Perfect_Hash_OpTable tao_TELESCOPE_MODULE_Telescope_optable;


// TAO_IDL - Generated from
// /alma/ACS-2025APR/TAO/ACE_wrappers/build/linux/TAO/TAO_IDL/be/be_visitor_interface/interface_ss.cpp:89



POA_TELESCOPE_MODULE::Telescope::Telescope ()
  : TAO_ServantBase ()
{
  this->optable_ = std::addressof(tao_TELESCOPE_MODULE_Telescope_optable);
}

POA_TELESCOPE_MODULE::Telescope::Telescope (const Telescope& rhs)
  : TAO_Abstract_ServantBase (rhs),
    TAO_ServantBase (rhs),
    POA_ACS::ACSComponent (rhs)
{
}


namespace POA_TELESCOPE_MODULE
{
  
  // TAO_IDL - Generated from
  // /alma/ACS-2025APR/TAO/ACE_wrappers/build/linux/TAO/TAO_IDL/be/be_visitor_operation/upcall_command_ss.cpp:79

  class observe_Telescope
    : public TAO::Upcall_Command
  {
  public:
    inline observe_Telescope (
      POA_TELESCOPE_MODULE::Telescope * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    void execute () override
    {
      TAO::SArg_Traits< ::TYPES::ImageType>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::TYPES::ImageType> (
          this->operation_details_,
          this->args_);
      
      TAO::SArg_Traits< ::TYPES::Position>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg< ::TYPES::Position> (
          this->operation_details_,
          this->args_,
          1);
        
      TAO::SArg_Traits< ::CORBA::Long>::in_arg_type arg_2 =
        TAO::Portable_Server::get_in_arg< ::CORBA::Long> (
          this->operation_details_,
          this->args_,
          2);
        
      retval =
        this->servant_->observe (
          arg_1
          , arg_2);
    }
  
  private:
    POA_TELESCOPE_MODULE::Telescope * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}
// TAO_IDL - Generated from
// /alma/ACS-2025APR/TAO/ACE_wrappers/build/linux/TAO/TAO_IDL/be/be_visitor_operation/operation_ss.cpp:167

void POA_TELESCOPE_MODULE::Telescope::observe_skel (
  TAO_ServerRequest & server_request,
  TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR (servant_upcall),
  TAO_ServantBase *servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const exceptions[] = 
    {
      SYSTEMErr::_tc_PositionOutOfLimitsEx
    };
  
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< ::TYPES::ImageType>::ret_val retval;
  TAO::SArg_Traits< ::TYPES::Position>::in_arg_val _tao_coordinates;
  TAO::SArg_Traits< ::CORBA::Long>::in_arg_val _tao_exposureTime;

  TAO::Argument * const args[] =
    {
      std::addressof(retval),
      std::addressof(_tao_coordinates),
      std::addressof(_tao_exposureTime)
    };
  
  POA_TELESCOPE_MODULE::Telescope * const impl =
    dynamic_cast<POA_TELESCOPE_MODULE::Telescope *> (servant);

  if (!impl)
    {
      throw ::CORBA::INTERNAL ();
    }

  observe_Telescope command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , 3
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , 1
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}


namespace POA_TELESCOPE_MODULE
{
  
  // TAO_IDL - Generated from
  // /alma/ACS-2025APR/TAO/ACE_wrappers/build/linux/TAO/TAO_IDL/be/be_visitor_operation/upcall_command_ss.cpp:79

  class moveTo_Telescope
    : public TAO::Upcall_Command
  {
  public:
    inline moveTo_Telescope (
      POA_TELESCOPE_MODULE::Telescope * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    void execute () override
    {
      TAO::SArg_Traits< ::TYPES::Position>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg< ::TYPES::Position> (
          this->operation_details_,
          this->args_,
          1);
        
      this->servant_->moveTo (
        arg_1);
    }
  
  private:
    POA_TELESCOPE_MODULE::Telescope * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}
// TAO_IDL - Generated from
// /alma/ACS-2025APR/TAO/ACE_wrappers/build/linux/TAO/TAO_IDL/be/be_visitor_operation/operation_ss.cpp:167

void POA_TELESCOPE_MODULE::Telescope::moveTo_skel (
  TAO_ServerRequest & server_request,
  TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR (servant_upcall),
  TAO_ServantBase *servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const exceptions[] = 
    {
      SYSTEMErr::_tc_PositionOutOfLimitsEx
    };
  
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< void>::ret_val retval;
  TAO::SArg_Traits< ::TYPES::Position>::in_arg_val _tao_coordinates;

  TAO::Argument * const args[] =
    {
      std::addressof(retval),
      std::addressof(_tao_coordinates)
    };
  
  POA_TELESCOPE_MODULE::Telescope * const impl =
    dynamic_cast<POA_TELESCOPE_MODULE::Telescope *> (servant);

  if (!impl)
    {
      throw ::CORBA::INTERNAL ();
    }

  moveTo_Telescope command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , 2
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , 1
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}


namespace POA_TELESCOPE_MODULE
{
  
  // TAO_IDL - Generated from
  // /alma/ACS-2025APR/TAO/ACE_wrappers/build/linux/TAO/TAO_IDL/be/be_visitor_operation/upcall_command_ss.cpp:79

  class getCurrentPosition_Telescope
    : public TAO::Upcall_Command
  {
  public:
    inline getCurrentPosition_Telescope (
      POA_TELESCOPE_MODULE::Telescope * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    void execute () override
    {
      TAO::SArg_Traits< ::TYPES::Position>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::TYPES::Position> (
          this->operation_details_,
          this->args_);
      
      retval =
        this->servant_->getCurrentPosition ();
    }
  
  private:
    POA_TELESCOPE_MODULE::Telescope * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}
// TAO_IDL - Generated from
// /alma/ACS-2025APR/TAO/ACE_wrappers/build/linux/TAO/TAO_IDL/be/be_visitor_operation/operation_ss.cpp:167

void POA_TELESCOPE_MODULE::Telescope::getCurrentPosition_skel (
  TAO_ServerRequest & server_request,
  TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR (servant_upcall),
  TAO_ServantBase *servant)
{TAO::SArg_Traits< ::TYPES::Position>::ret_val retval;

  TAO::Argument * const args[] =
    {
      std::addressof(retval)
    };
  
  POA_TELESCOPE_MODULE::Telescope * const impl =
    dynamic_cast<POA_TELESCOPE_MODULE::Telescope *> (servant);

  if (!impl)
    {
      throw ::CORBA::INTERNAL ();
    }

  getCurrentPosition_Telescope command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , 1
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , nullptr
                         , 0
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}




// TAO_IDL - Generated from
// /alma/ACS-2025APR/TAO/ACE_wrappers/build/linux/TAO/TAO_IDL/be/be_visitor_interface/interface_ss.cpp:155





::CORBA::Boolean POA_TELESCOPE_MODULE::Telescope::_is_a (const char* value)
{
  return
    (
      std::strcmp (value, "IDL:alma/ACS/ACSComponent:1.0") == 0 ||
      std::strcmp (value, "IDL:acsws/TELESCOPE_MODULE/Telescope:1.0") == 0 ||
      std::strcmp (value, "IDL:omg.org/CORBA/Object:1.0") == 0
    );
}

const char* POA_TELESCOPE_MODULE::Telescope::_interface_repository_id () const
{
  return "IDL:acsws/TELESCOPE_MODULE/Telescope:1.0";
}


// TAO_IDL - Generated from
// /alma/ACS-2025APR/TAO/ACE_wrappers/build/linux/TAO/TAO_IDL/be/be_visitor_interface/interface_ss.cpp:394



void POA_TELESCOPE_MODULE::Telescope::_dispatch (
  TAO_ServerRequest & req,
  TAO::Portable_Server::Servant_Upcall* servant_upcall)
{
  this->synchronous_upcall_dispatch (req, servant_upcall, this);
}


// TAO_IDL - Generated from
// /alma/ACS-2025APR/TAO/ACE_wrappers/build/linux/TAO/TAO_IDL/be/be_visitor_interface/interface_ss.cpp:354



TELESCOPE_MODULE::Telescope *
POA_TELESCOPE_MODULE::Telescope::_this ()
{
  TAO_Stub_Auto_Ptr stub (this->_create_stub ());
  ::CORBA::Boolean const _tao_opt_colloc = stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects ();
  ::CORBA::Object_var obj = new (std::nothrow) ::CORBA::Object (stub.get (), _tao_opt_colloc, this);
  if (obj.ptr ())
    {
      (void) stub.release ();
      return TAO::Narrow_Utils<::TELESCOPE_MODULE::Telescope>::unchecked_narrow (obj.in ());
    }
  return {};
}

#endif /* ifndef */

