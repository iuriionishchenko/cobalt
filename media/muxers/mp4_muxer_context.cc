// Copyright 2023 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/muxers/mp4_muxer_context.h"

#include "media/muxers/output_position_tracker.h"

namespace media {

Mp4MuxerContext::Mp4MuxerContext(
    std::unique_ptr<OutputPositionTracker> output_position_tracker)
    : output_position_tracker_(std::move(output_position_tracker)) {}

Mp4MuxerContext::~Mp4MuxerContext() = default;

// Track will be created and inserted to vector whatever arrives at
// Muxer.
absl::optional<size_t> Mp4MuxerContext::GetVideoIndex() const {
  return video_index_;
}

void Mp4MuxerContext::SetVideoIndex(size_t index) {
  CHECK(!video_index_.has_value());
  video_index_ = index;
}

absl::optional<size_t> Mp4MuxerContext::GetAudioIndex() const {
  return audio_index_;
}

void Mp4MuxerContext::SetAudioIndex(size_t index) {
  CHECK(!audio_index_.has_value());
  audio_index_ = index;
}

void Mp4MuxerContext::SetCurrentFragmentMoofOffset(size_t offset) {
  moof_offset_in_fragment_ = offset;
}

size_t Mp4MuxerContext::GetCurrentFragmentMoofOffset() const {
  return moof_offset_in_fragment_.value();
}

void Mp4MuxerContext::SetCurrentFragmentMdatOffset(size_t offset) {
  mdat_offset_in_fragment_ = offset;
}

size_t Mp4MuxerContext::GetCurrentFragmentMdatOffset() const {
  return mdat_offset_in_fragment_.value();
}

OutputPositionTracker& Mp4MuxerContext::GetOutputPositionTracker() const {
  return *output_position_tracker_;
}

}  // namespace media
