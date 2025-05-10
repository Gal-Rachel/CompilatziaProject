#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "ast.h"

// Define value types
typedef enum
{
    TYPE_UNKNOWN = 0,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_BOOL,
    TYPE_VOID
} ValueType;

// Error codes for semantic analysis
typedef enum
{
    SEMANTIC_OK = 0,
    SEMANTIC_ERROR_UNDEFINED_VARIABLE,
    SEMANTIC_ERROR_UNDEFINED_FUNCTION,
    SEMANTIC_ERROR_DUPLICATE_VARIABLE,
    SEMANTIC_ERROR_DUPLICATE_FUNCTION,
    SEMANTIC_ERROR_INVALID_RETURN_PLACEMENT,
    SEMANTIC_ERROR_MISSING_MAIN,
    SEMANTIC_ERROR_MULTIPLE_MAIN,
    SEMANTIC_ERROR_TYPE_MISMATCH,
    SEMANTIC_ERROR_EMPTY_BLOCK,
    SEMANTIC_ERROR_TOO_MANY_VARIABLES,
    SEMANTIC_ERROR_TOO_MANY_FUNCTIONS,
    SEMANTIC_ERROR_DEFAULT_VALUE_ORDER,
    SEMANTIC_ERROR_TOO_MANY_ARGUMENTS,
    SEMANTIC_ERROR_TOO_FEW_ARGUMENTS,
    SEMANTIC_ERROR_ARGUMENT_TYPE_MISMATCH,
    SEMANTIC_ERROR_DEFAULT_VALUE_TYPE_MISMATCH,
    SEMANTIC_ERROR_RETURN_TYPE_MISMATCH
} SemanticErrorCode;

// Function to perform semantic analysis on the AST
SemanticErrorCode analyze_semantics(ASTNode *root);

// Helper functions for specific checks
SemanticErrorCode check_variable_declaration(const char *name, ValueType type);
SemanticErrorCode check_variable_usage(const char *name);
SemanticErrorCode check_function_declaration(const char *name, int line_number);
SemanticErrorCode check_function_usage(const char *name);
SemanticErrorCode check_return_statement_placement(ASTNode *block);
SemanticErrorCode check_main_function(void);
SemanticErrorCode check_block_not_empty(ASTNode *block);
SemanticErrorCode check_param_default_values(ASTNode *param_list);
SemanticErrorCode check_function_arguments(const char *func_name, ASTNode *args);
SemanticErrorCode check_argument_types(const char *func_name, ASTNode *args);
SemanticErrorCode check_default_value_type(ValueType param_type, ASTNode *default_value);
SemanticErrorCode check_return_type(ASTNode *function_def, ASTNode *return_value);

// Helper function to get expression type
ValueType get_expression_type(ASTNode *expr);

// Error reporting function
void report_semantic_error(SemanticErrorCode error, const char *details, int line_number);

#endif // SEMANTIC_H