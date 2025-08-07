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

#ifndef ALIBABACLOUD_OOS_MODEL_LISTTASKEXECUTIONSRESULT_H_
#define ALIBABACLOUD_OOS_MODEL_LISTTASKEXECUTIONSRESULT_H_

#include <string>
#include <vector>
#include <utility>
#include <alibabacloud/core/ServiceResult.h>
#include <alibabacloud/oos/OosExport.h>

namespace AlibabaCloud
{
	namespace Oos
	{
		namespace Model
		{
			class ALIBABACLOUD_OOS_EXPORT ListTaskExecutionsResult : public ServiceResult
			{
			public:
				struct TaskExecution
				{
					std::string status;
					std::string loop;
					int loopBatchNumber;
					std::string taskAction;
					std::string childExecutionId;
					std::string extraData;
					std::string properties;
					std::string endDate;
					std::string createDate;
					std::string statusMessage;
					std::string startDate;
					std::string updateDate;
					std::string loopItem;
					std::string taskName;
					std::string parentTaskExecutionId;
					std::string outputs;
					std::string taskExecutionId;
					std::string templateId;
					std::string executionId;
				};


				ListTaskExecutionsResult();
				explicit ListTaskExecutionsResult(const std::string &payload);
				~ListTaskExecutionsResult();
				std::string getNextToken()const;
				int getMaxResults()const;
				std::vector<TaskExecution> getTaskExecutions()const;

			protected:
				void parse(const std::string &payload);
			private:
				std::string nextToken_;
				int maxResults_;
				std::vector<TaskExecution> taskExecutions_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_OOS_MODEL_LISTTASKEXECUTIONSRESULT_H_