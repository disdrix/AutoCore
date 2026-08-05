# Review A residual refresh: `Client_RecvCompleteDynamicObjective` (2026-07-29)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080ff00` |
| **VA** | `0x0080ff00` |
| **Canonical name** | `Client_RecvCompleteDynamicObjective` |
| **Scope** | Dual residual only — **not** a full-function re-dual |
| **Counterpart** | `B_aa_0080ff00_Client_RecvCompleteDynamicObjective_residual.md` |
| **Prior dual** | `A_aa_0080ff00_Client_RecvCompleteDynamicObjective.md` (2026-07-23 accept-with-gaps) |
| **Evidence** | Fresh Ghidra `decompile` `0x0080ff00`; `batch_decompile` callees `0x0052d8b0`, `0x009197a0`, `0x00533f90`; `read_memory` entry + `0x0080ff80` CompleteObjective site + UseObject path; sole caller via `get_function_callers`; PacketDispatch raw `case 0x2070` |
| **Verdict** | **accept-with-gaps** — prior static open gaps on opcode, thiscall character, and 15.0f picker **sealed**; runtime/diff + full type-3 enum + UI helper names still open |

---

## 1. Residuals closed

| Prior gap | Resolution | Confidence |
|---|---|---|
| Opcode binding not sealed in body | **Sealed via sole caller.** `Client_PacketDispatch` @ `0x00815710` is the only xref; raw `case 0x2070: Client_RecvCompleteDynamicObjective(param_2); return 1;`. Body does not self-check opcode (expected). | **High** |
| `CompleteObjective` thiscall character elided | **Sealed at call site `0x0080ff87`:** `mov ecx, [edi+0xe98]` then `push 1; push -1; push -1; push edx; call 0x00533f90`. ECX = local character; EDX = `*(packet+0x10)`. | **High** |
| Client register framing (EDI) | **Sealed.** Entry uses `[edi+0xe98]` for both `FUN_0052d8b0` this and hash path; CompleteObjective same; UI offsets `+0x107c/+0x10b0/+0x1034` all relative to EDI. Sole dispatch path supplies packet as stack arg (`param_2`). | **High** |
| `FUN_009197a0(0x41700000)` semantics | **Sealed as float radius 15.0.** Decompile: `void* FUN_009197a0(float radius)` — camera/player origin; prefer AutoPatrol waypoint if within `radius²`; else hash-traverse world objects, return first with dist² ≤ `radius²`. Immediate at call site: `push 0x41700000` (`15.0f`). | **High** |
| World-id compare field | **Sealed.** Match uses `*( *(obj+0xa8) + 0x34 ) == capturedTarget` — same def id slot `Client_SendUseObject` / `FindObjectiveMatchingTarget` use. | **High** |
| `FUN_0052d8b0(0,-1)` framing | **Sealed as character thiscall.** Entry: `mov ecx,[edi+0xe98]; push -1; push 0; call 0x0052d8b0`. Body: when `param_3==-1`, walk/clear tree at `char+0x50c`; with `param_2==0` the ResolveObjectTarget cleanup branch is **skipped**. | **High** |
| Always force-complete even on hash miss | Unchanged (prior High) — scan only feeds UseObject gate; CompleteObjective is unconditional. | **High** |

---

## 2. Control flow (unchanged; clean ≡ raw)

```
char = *(client_EDI + 0xe98)
FUN_0052d8b0(char, clearFlag=0, missionId=-1)   // wipe char+0x50c tree
pObj = CNDHash_LookupByKey(char+0x548, pkt+0x10)
worldTarget = -1
if pObj:
  for req in [pObj+0x158 .. +0x15c):
    if req.vtbl[+0x50]() == 3: worldTarget = req[6]; break
CVOGReaction_CompleteObjective(char, id@+0x10, -1, -1, force=1)
refresh UI +0x107c (+0x3d8 / +0x448 / +0x34c)
if dialog +0x10b0 open (+0x684): FUN_008af180(0); FUN_008a0370(); optional +0x664 vtbl+0x480
if worldTarget != -1:
  near = FUN_009197a0(15.0f)
  if near matches id@def+0x34 → Client_SendUseObject(client, near)
  else list-scan FUN_004294f0 / FUN_004022a0 → SendUseObject on match; CS release path
Client_RefreshOpenMissionUiWindows(client)
optional +0x1034 → FUN_0090cbc0
```

| Stage | Match |
|---|---|
| Character thiscall into clear + CompleteObjective | **Yes** (bytes) |
| Unconditional force CompleteObjective | **Yes** |
| Type-3 scan → optional UseObject only | **Yes** |
| UI refresh order | **Yes** |
| No invented modernizations | **Yes** |

---

## 3. Cross-artifact evidence (this residual)

| Artifact | Role |
|---|---|
| `raw/aa_0080ff00_…` | Authoritative body |
| `raw/aa_00815710_…` PacketDispatch | `case 0x2070` → this VA; `param_2` packet |
| `functions/aa_00533f90_…` CompleteObjective | thiscall signature; force skips failed req evals |
| `functions/aa_00916740_…` SendUseObject | same `*(obj+0xa8)+0x34` world-id; caller of this unit |
| Ghidra `read_memory` `0x0080ff00` / `0x0080ff80` / UseObject path | ECX character; push force/COIDs; `push 0x41700000` |
| Ghidra `decompile` `0x009197a0` | radius² nearest-object / AutoPatrol pick |
| Ghidra `decompile` `0x0052d8b0` | `char+0x50c` tree clear when id=-1 |
| Prior dual A/B 2026-07-23 | force / +0x10 / UseObject polarity already High |

---

## 4. Remaining gaps (accept)

1. **Requirement type enum** for `vtbl+0x50 == 3` beyond "first type-3 req; Collect ctor is type 2" — full map (Deliver / UseItem / …) not closed in this residual.
2. Formal names for `FUN_008af180` / `FUN_008a0370` / `FUN_0090cbc0` / dialog vcalls.
3. Exact meaning of `req[6]` field (world target / COID / sequence id) beyond "compared to `*(obj+0xa8)+0x34`".
4. Runtime packet capture + differential / bit-exact vs retail EXE.

**Verdict:** static dual residual for **opcode**, **character thiscall**, **15.0f nearest-object pick**, and **clear-tree thiscall** **sealed**. **accept-with-gaps.**
