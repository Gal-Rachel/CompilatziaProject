#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "ast.h"

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
    SEMANTIC_ERROR_DEFAULT_VALUE_ORDER
} SemanticErrorCode;

// Function to perform semantic analysis on the AST
SemanticErrorCode analyze_semantics(ASTNode *root);

// Helper functions for specific checks
SemanticErrorCode check_variable_declaration(const char *name);
SemanticErrorCode check_variable_usage(const char *name);
SemanticErrorCode check_function_declaration(const char *name);
SemanticErrorCode check_function_usage(const char *name);
SemanticErrorCode check_return_statement_placement(ASTNode *block);
SemanticErrorCode check_main_function(void);
SemanticErrorCode check_block_not_empty(ASTNode *block);
SemanticErrorCode check_param_default_values(ASTNode *param_list);

// Error reporting function
void report_semantic_error(SemanticErrorCode error, const char *details, int line_number);

#endif // SEMANTIC_H