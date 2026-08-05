# Function record: COList_Constructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbfb0` |
| **Canonical name** | `COList_Constructor` |
| **Ghidra name** | `FUN_004bbfb0` |
| **Address** | `0x004bbfb0`–`0x004bc17f` (**464 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / COList |
| **Completion status** | **Human-refined** + dual A/B **accept-with-gaps** 2026-07-29 (W27-L) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004bbfb0_COList_Constructor.md`, `reviews/B_aa_004bbfb0_COList_Constructor.md` |
| **Last reviewed** | `2026-07-29` (W27-L) |

## Alias

- `FUN_004bbfb0` (Ghidra)
- Prior: `Named_CalleeOf_Named_Client_InitInstance_004bbfb0`

## Purpose

**COList** C++ constructor: SEH-framed host init of size **0x58**, dual optional hash tables, fixed third table (`FUN_004bce90(5)`), three single-CS 0x2C lists, zeroed vector triples. Sole production call: `Client_InitInstance` with `(5,10)` → global `DAT_00b04830`.

## Signature (sealed)

```c
COList* __thiscall COList_Constructor(COList* self, int capA, int capB);
// ECX=this; ret 8; EAX=this
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=this | `8B F1` after SEH prolog | **High** |
| ret 8 | `C2 08 00` | **High** |
| vtbl | `C7 06 48 B4 9C 00` → `0x009cb448` | **High** |
| product COList | rdata `COList::Insert` | **High** |
| sizeof 0x58 | InitInstance `operator_new(0x58)` | **High** |

## Control flow (sealed)

```
SEH install (LAB_009a1742)
*this = PTR_FUN_009cb448
zero buffer triple bases
clamp capA,capB >= 0
store caps + has flags
if capA: new(0x34)+FUN_004bcf90(capA) else null → +0x04
if hasB: new(0x34)+FUN_004bcf90(capB) else null → +0x08
always: new(0x34)+FUN_004bce90(5) → +0x18
×3: new(0x2C)+ICS list (vtbl 009cb378) → +0x1C/+0x20/+0x24
flag +0x0E = 0
return this
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bbfb0_FUN_004bbfb0.md`
- Annotated: `docs/reconstruction/raw/aa_004bbfb0_FUN_004bbfb0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/COList_Constructor.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004bbfb0.cpp`

## Callers / callees

| Direction | Notes |
|---|---|
| **Caller** | `FUN_0094a6a0` only (`0x0094a7eb`) |
| **Callees** | `operator_new`, `FUN_004bcf90`, `FUN_004bce90`, `InitializeCriticalSection` |

## Related

- `aa_004bbc70` COList_Destructor
- `aa_004bd1b0` COList_ScalarDeletingDestructor
- Nested: `FUN_004bcf90`, `FUN_004bce90` (hash family; not OWN)

## Confidence

| Claim | Level |
|---|---|
| ABI / layout / InitInstance publish | **High** |
| Nested helper product English | **Partial** |
| Runtime / bit-exact | Open |
