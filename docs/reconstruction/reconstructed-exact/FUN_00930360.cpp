// =============================================================================
// FUN_00930360  (clean twin of Client_SortTargetListByViewAngle_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00930360
// Address:   0x00930360–0x00930691 inclusive (0x332 B)
// Canonical: Client_SortTargetListByViewAngle_Inferred
// Generated: 2026-08-05 MEGA-023 (replaces 2026-07-23 scaffold)
// See:       Client_SortTargetListByViewAngle_Inferred.cpp for full plate.
// =============================================================================

#include <cstdint>
#include <cmath>

struct TFID_16 {
  uint32_t dwCoidLo;
  uint32_t dwCoidHi;
  uint8_t bGlobal;
  uint8_t bPad0, bPad1, bPad2, bPad3, bPad4, bPad5, bPad6;
};

struct TargetScoreElem {
  void *obj;
  float score;
  float dist;
  float distSq;
};

extern float g_flOne;
extern float g_flZero;
extern float g_flLevelUpUiBase_Inferred;
extern float DAT_00aaa668;

extern "C" void FUN_004e8a40(const float *quat, float *outForward);
extern "C" void FUN_004e8ad0(const float *quat, float *outRight);
extern "C" void *Object_ResolveFromTFID(TFID_16 *tfid);
extern "C" void FUN_00408640(uint32_t count, void *vec, void *where, const void *value);
extern "C" void FUN_00409bd0(void *begin, void *end, int n, void *pred);
extern "C" void operator_delete(void *p);
extern "C" bool LAB_0092cdd0(const TargetScoreElem *left, const TargetScoreElem *right);

// Ghidra name entry — identical CF to Client_SortTargetListByViewAngle_Inferred.
extern "C" void FUN_00930360(void *client, TFID_16 *tfidList, unsigned *countInOut)
{
  int player = *(int *)((char *)client + 0xe98);
  int *interior =
      (int *)(*(int *)(*(int *)(player + 4) + 4) + 4 + player);
  int *vtbl = (int *)*interior;

  float *pfPos = ((float *(*)(void))vtbl[0x1a0 / 4])();
  float posX = pfPos[0], posY = pfPos[1], posZ = pfPos[2];

  float *pfQuat = ((float *(*)(void))vtbl[0x1a4 / 4])();
  float quat[4] = {pfQuat[0], pfQuat[1], pfQuat[2], pfQuat[3]};
  float forward[4], right[4];
  FUN_004e8a40(quat, forward);
  FUN_004e8ad0(quat, right);

  TargetScoreElem *begin = nullptr;
  TargetScoreElem *end = nullptr;
  TargetScoreElem *capEnd = nullptr;

  unsigned nIn = *countInOut;
  if (nIn != 0) {
    TFID_16 *cursor = tfidList;
    unsigned i = 0;
    do {
      void *obj = Object_ResolveFromTFID(cursor);
      if (obj != nullptr) {
        int *ovtbl = *(int **)obj;
        ((void (*)(void *))ovtbl[0x144 / 4])(obj);

        float dX = *(float *)((char *)obj + 0x80) - posX;
        float dY = *(float *)((char *)obj + 0x84) - posY;
        float dZ = *(float *)((char *)obj + 0x88) - posZ;
        float distSq = dX * dX + dY * dY + dZ * dZ;
        float dist = sqrtf(distSq);
        float score = g_flLevelUpUiBase_Inferred;

        if (g_flZero < dist) {
          float inv = g_flOne / dist;
          float uX = dX * inv, uY = dY * inv, uZ = dZ * inv;
          float fDot = forward[0] * uX + forward[1] * uY + forward[2] * uZ;
          float rDot = right[0] * uX + right[1] * uY + right[2] * uZ;
          if (rDot <= g_flZero)
            score = fDot + g_flOne;
          else
            score = fDot * DAT_00aaa668 - g_flOne;
        }

        TargetScoreElem value = {obj, score, dist, distSq};
        uint32_t size = begin ? (uint32_t)(end - begin) : 0;
        uint32_t cap = begin ? (uint32_t)(capEnd - begin) : 0;
        if (begin == nullptr || cap <= size) {
          void *triad[3] = {begin, end, capEnd};
          FUN_00408640(1, triad, end, &value);
          begin = (TargetScoreElem *)triad[0];
          end = (TargetScoreElem *)triad[1];
          capEnd = (TargetScoreElem *)triad[2];
        } else {
          *end = value;
          end += 1;
        }
      }
      cursor += 1;
      i += 1;
    } while (i < nIn);
  }

  uint32_t n = begin ? (uint32_t)(end - begin) : 0;
  FUN_00409bd0(begin, end, (int)n, (void *)&LAB_0092cdd0);

  unsigned outCount = 0;
  if (begin != nullptr) {
    TFID_16 *out = tfidList;
    for (unsigned j = 0; j < n; ++j) {
      *out = *(TFID_16 *)((char *)begin[j].obj + 0x160);
      out += 1;
      outCount += 1;
    }
  }
  *countInOut = outCount;
  if (begin != nullptr)
    operator_delete(begin);
}
