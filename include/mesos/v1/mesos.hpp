/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __MESOS_V1_HPP__
#define __MESOS_V1_HPP__

#include <ostream>

#include <boost/functional/hash.hpp>

#include <mesos/v1/mesos.pb.h> // ONLY USEFUL AFTER RUNNING PROTOC.

namespace mesos {
namespace v1 {

bool operator==(const CommandInfo& left, const CommandInfo& right);
bool operator==(const CommandInfo::URI& left, const CommandInfo::URI& right);
bool operator==(const Credential& left, const Credential& right);
bool operator==(const Environment& left, const Environment& right);
bool operator==(const ExecutorInfo& left, const ExecutorInfo& right);
bool operator==(const MasterInfo& left, const MasterInfo& right);

bool operator==(
    const ResourceStatistics& left,
    const ResourceStatistics& right);

bool operator==(const AgentInfo& left, const AgentInfo& right);
bool operator==(const Volume& left, const Volume& right);

bool operator==(const URL& left, const URL& right);

bool operator==(const TaskStatus& left, const TaskStatus& right);
bool operator!=(const TaskStatus& left, const TaskStatus& right);

inline bool operator==(const ContainerID& left, const ContainerID& right)
{
  return left.value() == right.value();
}


inline bool operator==(const ExecutorID& left, const ExecutorID& right)
{
  return left.value() == right.value();
}


inline bool operator==(const FrameworkID& left, const FrameworkID& right)
{
  return left.value() == right.value();
}


inline bool operator==(const FrameworkInfo& left, const FrameworkInfo& right)
{
  return (left.name() == right.name()) && (left.user() == right.user());
}


inline bool operator==(const OfferID& left, const OfferID& right)
{
  return left.value() == right.value();
}


inline bool operator==(const AgentID& left, const AgentID& right)
{
  return left.value() == right.value();
}


inline bool operator==(const TaskID& left, const TaskID& right)
{
  return left.value() == right.value();
}


inline bool operator==(const ContainerID& left, const std::string& right)
{
  return left.value() == right;
}


inline bool operator==(const ExecutorID& left, const std::string& right)
{
  return left.value() == right;
}


inline bool operator==(const FrameworkID& left, const std::string& right)
{
  return left.value() == right;
}


inline bool operator==(const OfferID& left, const std::string& right)
{
  return left.value() == right;
}


inline bool operator==(const AgentID& left, const std::string& right)
{
  return left.value() == right;
}


inline bool operator==(const TaskID& left, const std::string& right)
{
  return left.value() == right;
}


inline bool operator!=(const ContainerID& left, const ContainerID& right)
{
  return left.value() != right.value();
}


inline bool operator!=(const ExecutorID& left, const ExecutorID& right)
{
  return left.value() != right.value();
}


inline bool operator!=(const FrameworkID& left, const FrameworkID& right)
{
  return left.value() != right.value();
}


inline bool operator!=(const AgentID& left, const AgentID& right)
{
  return left.value() != right.value();
}


inline bool operator<(const ContainerID& left, const ContainerID& right)
{
  return left.value() < right.value();
}


inline bool operator<(const ExecutorID& left, const ExecutorID& right)
{
  return left.value() < right.value();
}


inline bool operator<(const FrameworkID& left, const FrameworkID& right)
{
  return left.value() < right.value();
}


inline bool operator<(const OfferID& left, const OfferID& right)
{
  return left.value() < right.value();
}


inline bool operator<(const AgentID& left, const AgentID& right)
{
  return left.value() < right.value();
}


inline bool operator<(const TaskID& left, const TaskID& right)
{
  return left.value() < right.value();
}


inline std::size_t hash_value(const CommandInfo::URI& uri)
{
  size_t seed = 0;

  if (uri.extract()) {
    seed += 11;
  }

  if (uri.executable()) {
    seed += 2003;
  }

  boost::hash_combine(seed, uri.value());
  return seed;
}


inline std::size_t hash_value(const ContainerID& containerId)
{
  size_t seed = 0;
  boost::hash_combine(seed, containerId.value());
  return seed;
}


inline std::size_t hash_value(const ExecutorID& executorId)
{
  size_t seed = 0;
  boost::hash_combine(seed, executorId.value());
  return seed;
}


inline std::size_t hash_value(const FrameworkID& frameworkId)
{
  size_t seed = 0;
  boost::hash_combine(seed, frameworkId.value());
  return seed;
}


inline std::size_t hash_value(const OfferID& offerId)
{
  size_t seed = 0;
  boost::hash_combine(seed, offerId.value());
  return seed;
}


inline std::size_t hash_value(const AgentID& agentId)
{
  size_t seed = 0;
  boost::hash_combine(seed, agentId.value());
  return seed;
}


inline std::size_t hash_value(const TaskID& taskId)
{
  size_t seed = 0;
  boost::hash_combine(seed, taskId.value());
  return seed;
}


inline std::ostream& operator<<(std::ostream& stream, const ACLs& acls)
{
  return stream << acls.DebugString();
}


inline std::ostream& operator<<(
    std::ostream& stream,
    const ContainerID& containerId)
{
  return stream << containerId.value();
}


inline std::ostream& operator<<(
    std::ostream& stream,
    const ContainerInfo& containerInfo)
{
  return stream << containerInfo.DebugString();
}


inline std::ostream& operator<<(
    std::ostream& stream,
    const ExecutorID& executorId)
{
  return stream << executorId.value();
}


inline std::ostream& operator<<(
    std::ostream& stream,
    const ExecutorInfo& executor)
{
  return stream << executor.DebugString();
}


inline std::ostream& operator<<(
    std::ostream& stream,
    const FrameworkID& frameworkId)
{
  return stream << frameworkId.value();
}


inline std::ostream& operator<<(std::ostream& stream, const MasterInfo& master)
{
  return stream << master.DebugString();
}


inline std::ostream& operator<<(std::ostream& stream, const OfferID& offerId)
{
  return stream << offerId.value();
}


inline std::ostream& operator<<(std::ostream& stream, const RateLimits& limits)
{
  return stream << limits.DebugString();
}


inline std::ostream& operator<<(std::ostream& stream, const AgentID& agentId)
{
  return stream << agentId.value();
}


inline std::ostream& operator<<(std::ostream& stream, const AgentInfo& agent)
{
  return stream << agent.DebugString();
}


inline std::ostream& operator<<(std::ostream& stream, const TaskID& taskId)
{
  return stream << taskId.value();
}


inline std::ostream& operator<<(std::ostream& stream, const TaskInfo& task)
{
  return stream << task.DebugString();
}


inline std::ostream& operator<<(std::ostream& stream, const TaskState& state)
{
  return stream << TaskState_Name(state);
}


inline std::ostream& operator<<(
    std::ostream& stream,
    const std::vector<TaskID>& taskIds)
{
  stream << "[ ";
  for (auto it = taskIds.begin(); it != taskIds.end(); ++it) {
    if (it != taskIds.begin()) {
      stream << ", ";
    }
    stream << *it;
  }
  stream << " ]";
  return stream;
}


inline std::ostream& operator<<(
    std::ostream& stream,
    const FrameworkInfo::Capability& capability)
{
  return stream << FrameworkInfo::Capability::Type_Name(capability.type());
}


template <typename T>
inline std::ostream& operator<<(
    std::ostream& stream,
    const google::protobuf::RepeatedPtrField<T>& messages)
{
  stream << "[ ";
  for (auto it = messages.begin(); it != messages.end(); ++it) {
    if (it != messages.begin()) {
      stream << ", ";
    }
    stream << *it;
  }
  stream << " ]";
  return stream;
}

} // namespace v1 {
} // namespace mesos {

#endif // __MESOS_V1_HPP__