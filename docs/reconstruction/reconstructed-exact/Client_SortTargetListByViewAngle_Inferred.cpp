// =============================================================================
// Client_SortTargetListByViewAngle_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00930360
// Address:   0x00930360–0x00930691 inclusive (0x332 B)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities / client target selection
// Generated: 2026-08-05 MEGA-023 dual seal (live decompile + disassemble + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra name: FUN_00930360
// Retired scaffold: Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_00930360
// =============================================================================

// PURPOSE:
// Reorder an in/out TFID_16 target list by a view-angle score derived from the
// local player's orientation (forward/right basis) and each resolved object's
// world position. Used by Client_CycleHostileTarget_Inferred after
// Skill_GatherTargetsInArea to define hostile tab-cycle order.
//
// Stages:
//   1. Read player origin (vtbl+0x1a0) and quat (vtbl+0x1a4) via client+0xe98.
//   2. Extract forward (FUN_004e8a40) and right (FUN_004e8ad0 / Quat_ExtractRight).
//   3. For each TFID: resolve object, score by forward/right dots, push Elem0x10.
//   4. Sort vector ascending by score float@+4 (LAB_0092cdd0).
//   5. Write object TFID blobs (obj+0x160) back into the list; update *count.
//   6. Free vector buffer.
//
// ABI (sealed):
//   stdcall RET 0xC (C2 0C 00)
//   stack: void* client, TFID_16* list, unsigned* countInOut
//   void return (not ECX thiscall)

#include <cstdint>
#include <cmath>

struct TFID_16 {
  uint32_t dwCoidLo;
  uint32_t dwCoidHi;
  uint8_t bGlobal;
  uint8_t bPad0, bPad1, bPad2, bPad3, bPad4, bPad5, bPad6;
};

// Temporary scored element (vector stride 0x10). Sort key = score @ +4.
struct TargetScoreElem {
  void *obj;     // +0x00
  float score;   // +0x04  sort key
  float dist;    // +0x08
  float distSq;  // +0x0c  (construct path may store distSq; not used by cmp)
};

extern float g_flOne;                      // 0x00a0f2a0 = 1.0f
extern float g_flZero;                     // 0x00a0f518 = 0.0f
extern float g_flLevelUpUiBase_Inferred;   // 0x00a10e74 = 2.0f (default score)
extern float DAT_00aaa668;                 // 0x00aaa668 = -1.0f

extern "C" void FUN_004e8a40(const float *quat, float *outForward);
extern "C" void FUN_004e8ad0(const float *quat, float *outRight); // Quat_ExtractRight_Inferred
extern "C" void *Object_ResolveFromTFID(TFID_16 *tfid);           // 0x004bb950
extern "C" void FUN_00408640(uint32_t count /*ECX*/, void *vec /*EDX*/,
                             void *where, const void *value);     // InsertN elem0x10
extern "C" void FUN_00409e20(/* construct-N path; arity per asm */);
extern "C" void FUN_00409bd0(void *begin, void *end, int n, void *pred);
extern "C" void operator_delete(void *p);

// Comparator LAB_0092cdd0 — returns true when left.score < right.score (ascending).
extern "C" bool LAB_0092cdd0(const TargetScoreElem *left, const TargetScoreElem *right);

extern "C" void Client_SortTargetListByViewAngle_Inferred(
    void *client,
    TFID_16 *tfidList,
    unsigned *countInOut)
{
  // SEH: LAB_009ac665 — omitted as non-semantic for port

  // --- player interior @ client+0xe98 --------------------------------------
  int player = *(int *)((char *)client + 0xe98);
  int *interior =
      (int *)(*(int *)(*(int *)(player + 4) + 4) + 4 + player);
  int *vtbl = (int *)*interior;

  // vtbl[+0x1a0] → float3 position
  float *pfPos = ((float *(*)(void))vtbl[0x1a0 / 4])();
  float posX = pfPos[0];
  float posY = pfPos[1];
  float posZ = pfPos[2];

  // vtbl[+0x1a4] → float4 quat XYZW
  float *pfQuat = ((float *(*)(void))vtbl[0x1a4 / 4])();
  float quat[4] = {pfQuat[0], pfQuat[1], pfQuat[2], pfQuat[3]};

  float forward[4];
  float right[4];
  FUN_004e8a40(quat, forward);
  FUN_004e8ad0(quat, right);

  // std::vector-like triad of TargetScoreElem (begin/end/capEnd)
  TargetScoreElem *begin = nullptr;
  TargetScoreElem *end = nullptr;
  TargetScoreElem *capEnd = nullptr;
  // stack triad mirrors: pvStack_7c / iStack_78 / iStack_74

  unsigned nIn = *countInOut;
  if (nIn != 0) {
    TFID_16 *cursor = tfidList;
    unsigned i = 0;
    do {
      // Site also loads ECX = *(client+0xd34) before CALL 004bb950
      void *obj = Object_ResolveFromTFID(cursor);
      if (obj != nullptr) {
        int *ovtbl = *(int **)obj;
        ((void (*)(void *))ovtbl[0x144 / 4])(obj); // virtual +0x144

        // Object world pos at +0x80/+0x84/+0x88 (X/Y/Z); matches asm MOVSS loads.
        float dX = *(float *)((char *)obj + 0x80) - posX;
        float dY = *(float *)((char *)obj + 0x84) - posY;
        float dZ = *(float *)((char *)obj + 0x88) - posZ;

        float distSq = dX * dX + dY * dY + dZ * dZ;
        float dist = sqrtf(distSq);
        float score = g_flLevelUpUiBase_Inferred; // 2.0f default

        if (g_flZero < dist) {
          float inv = g_flOne / dist;
          float uX = dX * inv;
          float uY = dY * inv;
          float uZ = dZ * inv;
          // forward · unit  (FUN_004e8a40 out XYZ)
          float fDot = forward[0] * uX + forward[1] * uY + forward[2] * uZ;
          // right · unit    (FUN_004e8ad0 out XYZ)
          float rDot = right[0] * uX + right[1] * uY + right[2] * uZ;
          if (rDot <= g_flZero) {
            score = fDot + g_flOne;
          } else {
            score = fDot * DAT_00aaa668 - g_flOne; // -fDot - 1
          }
        }

        TargetScoreElem value;
        value.obj = obj;
        value.score = score;
        value.dist = dist;
        value.distSq = distSq;

        // Capacity check: (capEnd-begin)>>4 <= (end-begin)>>4  → grow path
        // Mirrors asm: if begin==0 OR size>=capacity → InsertN; else construct-N
        uint32_t size = begin ? (uint32_t)(end - begin) : 0;
        uint32_t cap = begin ? (uint32_t)(capEnd - begin) : 0;
        if (begin == nullptr || cap <= size) {
          // FUN_00408640(ECX=1, EDX=&triad, where=end, value=&value)
          // After insert, refresh begin/end from triad.
          void *triad[3] = {begin, end, capEnd};
          FUN_00408640(1, triad, end, &value);
          begin = (TargetScoreElem *)triad[0];
          end = (TargetScoreElem *)triad[1];
          capEnd = (TargetScoreElem *)triad[2];
        } else {
          // In-capacity construct at end (FUN_00409e20 path); end += 1 elem
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

  // Rewrite sorted TFIDs into caller's array
  unsigned outCount = 0;
  if (begin != nullptr) {
    TFID_16 *out = tfidList;
    for (unsigned j = 0; j < n; ++j) {
      void *obj = begin[j].obj;
      // 16-byte TFID copy from obj+0x160
      *out = *(TFID_16 *)((char *)obj + 0x160);
      out += 1;
      outCount += 1;
    }
  }
  *countInOut = outCount;

  if (begin != nullptr) {
    operator_delete(begin); // returns — decompiler noreturn warning is false
  }
  // SEH teardown; RET 0xC
}
