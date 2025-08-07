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

#ifndef ALIBABACLOUD_TEAMBITION_ALIYUN_MODEL_LISTPROJECTTASKSRESULT_H_
#define ALIBABACLOUD_TEAMBITION_ALIYUN_MODEL_LISTPROJECTTASKSRESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/teambition-aliyun/Teambition_aliyunExport.h>

namespace AlibabaCloud
{
	namespace Teambition_aliyun
	{
		namespace Model
		{
			class ALIBABACLOUD_TEAMBITION_ALIYUN_EXPORT ListProjectTasksResult : public ServiceResult
			{
			public:
				struct Task
				{
					std::string taskgroupId;
					std::string updated;
					std::string creatorId;
					std::string projectId;
					std::string id;
					std::string tasklistId;
					std::string modifierId;
					std::string name;
					std::string created;
				};


				ListProjectTasksResult();
				explicit ListProjectTasksResult(const std::string &payload);
				~ListProjectTasksResult();
				std::string getErrorMsg()const;
				std::vector<Task> getObject()const;
				std::string getErrorCode()const;
				bool getSuccessful()const;

			protected:
				void parse(const std::string &payload);
			private:
				std::string errorMsg_;
				std::vector<Task> object_;
				std::string errorCode_;
				bool successful_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_TEAMBITION_ALIYUN_MODEL_LISTPROJECTTASKSRESULT_H_