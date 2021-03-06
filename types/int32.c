/**
 *  Copyright 2009-2014 MongoDB, Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
#include <php.h>
#include "../php_mongo.h"

zend_class_entry *mongo_ce_Int32 = NULL;

/* {{{ MongoInt32::__construct(string)
 */
PHP_METHOD(MongoInt32, __construct)
{
	char *value;
	int value_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &value, &value_len) == FAILURE) {
		return;
	}

	zend_update_property_stringl(mongo_ce_Int32, getThis(), "value", strlen("value"), value, value_len TSRMLS_CC);
}
/* }}} */

/* {{{ MongoInt32::__toString()
 */
PHP_METHOD(MongoInt32, __toString)
{
	zval *zode = zend_read_property(mongo_ce_Int32, getThis(), "value", strlen("value"), NOISY TSRMLS_CC);

	RETURN_STRING(Z_STRVAL_P(zode), 1 );
}
/* }}} */

static zend_function_entry MongoInt32_methods[] = {
	PHP_ME(MongoInt32, __construct, NULL, ZEND_ACC_PUBLIC )
	PHP_ME(MongoInt32, __toString, NULL, ZEND_ACC_PUBLIC )
	PHP_FE_END
};

void mongo_init_MongoInt32(TSRMLS_D)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, "MongoInt32", MongoInt32_methods);
	ce.create_object = php_mongo_type_object_new;
	mongo_ce_Int32 = zend_register_internal_class(&ce TSRMLS_CC);

	zend_declare_property_string(mongo_ce_Int32, "value", strlen("value"), "", ZEND_ACC_PUBLIC|MONGO_ACC_READ_ONLY TSRMLS_CC);
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: fdm=marker
 * vim: noet sw=4 ts=4
 */
