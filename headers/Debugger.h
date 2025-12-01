#ifndef DEBUGGER_H
#define DEBUGGER_H
/**
 * @file debugger.h
 * @brief Header file for debugging macros.
 * @author Mohammad Ajmal Siddiqui
 *
 * The provided code is a debugger header file with macros for different types of debugging messages.
 * It allows you  to control the debugging behavior by modifying the predefined macros.
 *
 * Logging Macros:
 *   - DEBUG(x): Outputs the provided text x to the standard output stream (std::cout).
 *   - DEBUG_CODE(x): Wraps code blocks that should be conditionally included for debugging purposes.
 *
 * Usage Examples:
 *   ' DEBUG("Some Text") ' will output the text "Some Text" to the console if DEBUG_ENABLED is true.
 *   ' UNIT_A && DEBUG("SOME TEXT") ' is a logical AND operation where the right operand (DEBUG("SOME TEXT")) will only be evaluated and executed if UNIT_A is true and DEBUG_ENABLED is true.
 *   ' DEBUG_CODE({ // code... }) ' is used to wrap code blocks that should only be included when DEBUG_ENABLED is true. The code within the curly braces will be executed if DEBUG_ENABLED is true.
 *   ' #if UNIT_A and #endif ' are used to conditionally compile the code block within the DEBUG_CODE({ // code... }) when UNIT_A is true. This allows for additional conditional compilation based on specific modules or units.
 *
 * Note:
 *  The provided code is designed to be flexible and allows you to customize the logging behavior for different modules or units in your application.
 *  By enabling or disabling the macros, you can selectively include or exclude debugging statements to improve the performance of performance-sensitive applications.
*/

#define DEBUG_ENABLED           true
#define COMM_HANDLER_DEBUG      false
#define GLOBAL_VARIABLE_DEBUG   false
#define ABSTRACT_MODEL_DEBUG    false
#define SYSTEM_DEBUG            false
#define MSU_MODEL_DEBUG         false

#if DEBUG_ENABLED
#include <QDebug>
#define DEBUG(x) [&](){qDebug()<< x;return true;}();
#define DEBUG_CODE(x) x
#else
#define DEBUG(...) false;
#define DEBUG_CODE(...)
#endif

#endif // DEBUGGER_H
