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

#ifndef ALIBABACLOUD_DATALAKE_MODEL_DELETEDATABASEREQUEST_H_
#define ALIBABACLOUD_DATALAKE_MODEL_DELETEDATABASEREQUEST_H_

#include <alibabacloud/datalake/DataLakeExport.h>
#include <alibabacloud/core/RoaServiceRequest.h>
#include <string>
#include <vector>
#include <map>

namespace AlibabaCloud {
namespace DataLake {
namespace Model {
class ALIBABACLOUD_DATALAKE_EXPORT DeleteDatabaseRequest : public RoaServiceRequest {
public:
	DeleteDatabaseRequest();
	~DeleteDatabaseRequest();
	bool getAsync() const;
	void setAsync(bool async);
	std::string getCatalogId() const;
	void setCatalogId(const std::string &catalogId);
	bool getCascade() const;
	void setCascade(bool cascade);
	std::string getName() const;
	void setName(const std::string &name);

private:
	bool async_;
	std::string catalogId_;
	bool cascade_;
	std::string name_;
};
} // namespace Model
} // namespace DataLake
} // namespace AlibabaCloud
#endif // !ALIBABACLOUD_DATALAKE_MODEL_DELETEDATABASEREQUEST_H_
