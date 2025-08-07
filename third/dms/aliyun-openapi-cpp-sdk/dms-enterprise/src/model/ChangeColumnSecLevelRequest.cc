/*
 * Copyright 2009-2017 Alibaba Cloud All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <alibabacloud/dms-enterprise/model/ChangeColumnSecLevelRequest.h>

using AlibabaCloud::Dms_enterprise::Model::ChangeColumnSecLevelRequest;

ChangeColumnSecLevelRequest::ChangeColumnSecLevelRequest()
    : RpcServiceRequest("dms-enterprise", "2018-11-01", "ChangeColumnSecLevel") {
  setMethod(HttpRequest::Method::Post);
}

ChangeColumnSecLevelRequest::~ChangeColumnSecLevelRequest() {}

long ChangeColumnSecLevelRequest::getTid() const {
  return tid_;
}

void ChangeColumnSecLevelRequest::setTid(long tid) {
  tid_ = tid;
  setParameter(std::string("Tid"), std::to_string(tid));
}

std::string ChangeColumnSecLevelRequest::getTableName() const {
  return tableName_;
}

void ChangeColumnSecLevelRequest::setTableName(const std::string &tableName) {
  tableName_ = tableName;
  setParameter(std::string("TableName"), tableName);
}

std::string ChangeColumnSecLevelRequest::getSchemaName() const {
  return schemaName_;
}

void ChangeColumnSecLevelRequest::setSchemaName(const std::string &schemaName) {
  schemaName_ = schemaName;
  setParameter(std::string("SchemaName"), schemaName);
}

bool ChangeColumnSecLevelRequest::getIsLogic() const {
  return isLogic_;
}

void ChangeColumnSecLevelRequest::setIsLogic(bool isLogic) {
  isLogic_ = isLogic;
  setParameter(std::string("IsLogic"), isLogic ? "true" : "false");
}

std::string ChangeColumnSecLevelRequest::getNewLevel() const {
  return newLevel_;
}

void ChangeColumnSecLevelRequest::setNewLevel(const std::string &newLevel) {
  newLevel_ = newLevel;
  setParameter(std::string("NewLevel"), newLevel);
}

std::string ChangeColumnSecLevelRequest::getColumnName() const {
  return columnName_;
}

void ChangeColumnSecLevelRequest::setColumnName(const std::string &columnName) {
  columnName_ = columnName;
  setParameter(std::string("ColumnName"), columnName);
}

long ChangeColumnSecLevelRequest::getDbId() const {
  return dbId_;
}

void ChangeColumnSecLevelRequest::setDbId(long dbId) {
  dbId_ = dbId;
  setParameter(std::string("DbId"), std::to_string(dbId));
}

