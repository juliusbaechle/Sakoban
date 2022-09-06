#pragma once

#include "Playground.h"

Playground level12 = {
  { { 0, 0 }, { FieldValue::Wall } },
  { { 1, 0 }, { FieldValue::Wall } },
  { { 2, 0 }, { FieldValue::Wall } },
  { { 3, 0 }, { FieldValue::Wall } },
  { { 4, 0 }, { FieldValue::Wall } },
  { { 5, 0 }, { FieldValue::Wall } },
  { { 6, 0 }, { FieldValue::Background } },
  { { 7, 0 }, { FieldValue::Background } },
  { { 8, 0 }, { FieldValue::Background } },

  { { 0, 1 }, { FieldValue::Wall } },
  { { 1, 1 }, { FieldValue::Space } },
  { { 2, 1 }, { FieldValue::Space } },
  { { 3, 1 }, { FieldValue::Space } },
  { { 4, 1 }, { FieldValue::Space } },
  { { 5, 1 }, { FieldValue::Wall } },
  { { 6, 1 }, { FieldValue::Background } },
  { { 7, 1 }, { FieldValue::Background } },
  { { 8, 1 }, { FieldValue::Background } },

  { { 0, 2 }, { FieldValue::Wall } },
  { { 1, 2 }, { FieldValue::Space } },
  { { 2, 2 }, { FieldValue::Box } },
  { { 3, 2 }, { FieldValue::Space } },
  { { 4, 2 }, { FieldValue::Player } },
  { { 5, 2 }, { FieldValue::Wall } },
  { { 6, 2 }, { FieldValue::Background } },
  { { 7, 2 }, { FieldValue::Background } },
  { { 8, 2 }, { FieldValue::Background } },

  { { 0, 3 }, { FieldValue::Wall } },
  { { 1, 3 }, { FieldValue::Wall } },
  { { 2, 3 }, { FieldValue::Box, FieldValue::Target } },
  { { 3, 3 }, { FieldValue::Space } },
  { { 4, 3 }, { FieldValue::Space } },
  { { 5, 3 }, { FieldValue::Wall } },
  { { 6, 3 }, { FieldValue::Background } },
  { { 7, 3 }, { FieldValue::Background } },
  { { 8, 3 }, { FieldValue::Background } },

  { { 0, 4 }, { FieldValue::Wall } },
  { { 1, 4 }, { FieldValue::Space } },
  { { 2, 4 }, { FieldValue::Box, FieldValue::Target } },
  { { 3, 4 }, { FieldValue::Space } },
  { { 4, 4 }, { FieldValue::Wall } },
  { { 5, 4 }, { FieldValue::Wall } },
  { { 6, 4 }, { FieldValue::Background } },
  { { 7, 4 }, { FieldValue::Background } },
  { { 8, 4 }, { FieldValue::Background } },

  { { 0, 5 }, { FieldValue::Wall } },
  { { 1, 5 }, { FieldValue::Space } },
  { { 2, 5 }, { FieldValue::Box, FieldValue::Target } },
  { { 3, 5 }, { FieldValue::Space } },
  { { 4, 5 }, { FieldValue::Wall } },
  { { 5, 5 }, { FieldValue::Background } },
  { { 6, 5 }, { FieldValue::Background } },
  { { 7, 5 }, { FieldValue::Background } },
  { { 8, 5 }, { FieldValue::Background } },

  { { 0, 6 }, { FieldValue::Wall } },
  { { 1, 6 }, { FieldValue::Space } },
  { { 2, 6 }, { FieldValue::Box, FieldValue::Target } },
  { { 3, 6 }, { FieldValue::Space } },
  { { 4, 6 }, { FieldValue::Wall } },
  { { 5, 6 }, { FieldValue::Background } },
  { { 6, 6 }, { FieldValue::Background } },
  { { 7, 6 }, { FieldValue::Background } },
  { { 8, 6 }, { FieldValue::Background } },

  { { 0, 7 }, { FieldValue::Wall } },
  { { 1, 7 }, { FieldValue::Space } },
  { { 2, 7 }, { FieldValue::Space, FieldValue::Target } },
  { { 3, 7 }, { FieldValue::Space } },
  { { 4, 7 }, { FieldValue::Wall } },
  { { 5, 7 }, { FieldValue::Background } },
  { { 6, 7 }, { FieldValue::Background } },
  { { 7, 7 }, { FieldValue::Background } },
  { { 8, 7 }, { FieldValue::Background } },

  { { 0, 8 }, { FieldValue::Wall } },
  { { 1, 8 }, { FieldValue::Wall } },
  { { 2, 8 }, { FieldValue::Wall } },
  { { 3, 8 }, { FieldValue::Wall } },
  { { 4, 8 }, { FieldValue::Wall } },
  { { 5, 8 }, { FieldValue::Background } },
  { { 6, 8 }, { FieldValue::Background } },
  { { 7, 8 }, { FieldValue::Background } },
  { { 8, 8 }, { FieldValue::Background } }
};
