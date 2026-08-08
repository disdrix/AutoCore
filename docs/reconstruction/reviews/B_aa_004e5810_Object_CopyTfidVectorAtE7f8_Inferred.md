# Review B (skeptical / adversarial): `aa_004e5810` Object_CopyTfidVectorAtE7f8_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e5810` |
| **VA** | `0x004e5810` |
| **Canonical name** | `Object_CopyTfidVectorAtE7f8_Inferred` |
| **Review date** | `2026-08-05` (R13-026) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_004e5810_Object_CopyTfidVectorAtE7f8_Inferred.md` |
| **System** | inventory-transfer — object TFID vector materialize |
| **Verdict** | **accept-with-gaps** — agree with A |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context` (no `disassemble_bytes`). No Launcher.

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_004e5810` only | Scaffold OK; under-describes sealed offset + vector role |
| `Named_CalleeOf_*RefreshOpenMissionUi*` | **Reject** — chain-of-caller plate; body has zero mission IDs/strings |
| Inventory grid place / find / footprint | **Reject** — no X/Y, COID stamp, type switch |
| In-place mutate / clear source vector | **Reject** — callee constructs dest; source is read via `param_2` |
| Count-only / size getter | **Reject** — returns shell*; count is caller-side `SAR 3` |
| Resolve TFID / walk stations | **Reject** — no resolve/call loop in body; that is callers |
| cdecl / no stack cleanup | **Reject** — thiscall + `RET 4` |
| Character method (not Object) | **Reject as primary** — ECX is object (often MI+0xa8 under character); offset is on object layout |
| Product English without `_Inferred` | **Reject** — member lexicon unproven |
| `Object_CopyTfidVectorAtE7f8_Inferred` | **Accept** — offset + vector copy + TFID consumers; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Decompiler shows only one arg → no out shell | **Fails** — stack load `MOV ESI,[ESP+0xC]`; `RET 4`; callers push LEA of local |
| `FUN_004e53e0(this+0xe7f8)` means this of worker is source | **Fails** — live `MOV ECX,ESI` (dest) then `PUSH` source; worker writes dest `+4/+8/+0xc` from source |
| Body is large / multi-path | **Fails** — 35 B straight-line wrapper |
| Four xrefs are four different semantics | **Fails** — all materialize TFID vector then count/index; two parents only |
| Elem size is 4 (dword vector) | **Fails** — callers `SAR 3` (=÷8); resolve takes two dwords per elem |
| `MOV [ESP+8],0` mutates object | **Fails** — zeros spill slot of original ECX after ADD; not a member store |
| Runtime Confirmed for craft list English | **Fails** — no runtime; keep `_Inferred` / Terminal false |
| Same as free-function global TFID table | **Fails** — ECX this + member offset |

---

## 3. Cross-check against raw + bytes

```text
PUSH ECX; PUSH ESI
ESI = out*
ECX = this + 0xe7f8
PUSH ECX                  ; src
MOV  ECX, ESI             ; dest this
MOV  [ESP+8], 0           ; dead spill zero
CALL 004e53e0
EAX = ESI
POP ESI; POP ECX
RET 4
```

Caller samples:
```text
; craft gate 0052eb90
LEA  EAX, [ESP+14]
PUSH EAX
MOV  ECX, [object]        ; MI+0xa8
CALL 004e5810
; count via [EAX+4]/[EAX+8] >> 3
; later second CALL for indexed TFID → Resolve via +0xe4e8

; station walk 004dd940
LEA  EAX, [ESP+1c]
PUSH EAX
MOV  ECX, ESI             ; object
CALL 004e5810
; same count / index / ResolveObjectTarget / subtype 0xD/0xE/0xF
```

Clean must **not** invent mission UI, inventory footprint, in-body TFID walk, source mutation, or claim product demangle / Runtime Confirmed.

---

## 4. Agreement with Review A

- CF + thiscall RET 4 + `+0xe7f8` + vector copy wrapper: **agree High**
- Name with `_Inferred`: **agree**
- Gaps (member English, dual of `004e53e0`, runtime): **agree open**

---

## 5. Surviving contract for AutoCore

```csharp
// Materialize a temporary copy of Object.TfidVector @ +0xe7f8
// (8-byte TFID pairs). Caller owns shell lifetime / operator_delete of buffer.
VectorU64Shell* CopyTfidVectorAtE7f8(Object self, VectorU64Shell* out)
{
    // FUN_004e53e0: std::vector copy-construct, elem size 8
    VectorCopyConstruct_U64(out, /*src=*/ self + 0xE7F8);
    return out;
}
```

Port must keep **member offset `0xe7f8`**, **elem stride 8**, **thiscall + ret 4**, and **not** merge with resolve/walk callers or the copy-worker body.

---

## 6. Gaps (agree with A)

1. Product English for `+0xe7f8`.
2. Dual of `FUN_004e53e0` / `FUN_006a2be0`.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
