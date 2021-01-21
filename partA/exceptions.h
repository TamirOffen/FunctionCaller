
#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>

namespace mtm 
{
    class Exception: public std::exception {};
    class InvalidDate: public Exception {};
    class NegativeDays: public Exception {};
    class AlreadyRegistered: public Exception {};
    class RegistrationBlocked: public Exception {};
    class NotRegistered: public Exception {};
    class AlreadyInvited: public Exception {};
    class NotSupported: public Exception {};
    class DateMismatch: public Exception {};
    class InvalidNumber: public Exception {};
    class InvalidInterval: public Exception {};
    class EventAlreadyExists: public Exception {};
    class EventDoesNotExist: public Exception {};
    class InvalidStudent: public Exception {};
}


#endif



