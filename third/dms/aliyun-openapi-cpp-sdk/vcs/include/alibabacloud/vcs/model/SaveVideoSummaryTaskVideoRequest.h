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

#ifndef ALIBABACLOUD_VCS_MODEL_SAVEVIDEOSUMMARYTASKVIDEOREQUEST_H_
#define ALIBABACLOUD_VCS_MODEL_SAVEVIDEOSUMMARYTASKVIDEOREQUEST_H_

#include <string>
#include <vector>
#include <alibabacloud/core/RpcServiceRequest.h>
#include <alibabacloud/vcs/VcsExport.h>

namespace AlibabaCloud
{
	namespace Vcs
	{
		namespace Model
		{
			class ALIBABACLOUD_VCS_EXPORT SaveVideoSummaryTaskVideoRequest : public RpcServiceRequest
			{

			public:
				SaveVideoSummaryTaskVideoRequest();
				~SaveVideoSummaryTaskVideoRequest();

				std::string getCorpId()const;
				void setCorpId(const std::string& corpId);
				bool getSaveVideo()const;
				void setSaveVideo(bool saveVideo);
				long getTaskId()const;
				void setTaskId(long taskId);

            private:
				std::string corpId_;
				bool saveVideo_;
				long taskId_;

			};
		}
	}
}
#endif // !ALIBABACLOUD_VCS_MODEL_SAVEVIDEOSUMMARYTASKVIDEOREQUEST_H_