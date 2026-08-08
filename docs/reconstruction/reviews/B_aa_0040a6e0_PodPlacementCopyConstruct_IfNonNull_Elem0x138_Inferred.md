# Review B (skeptical / adversarial): `aa_0040a6e0` PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040a6e0` |
| **VA** | `0x0040a6e0` |
| **Canonical name** | `PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred` |
| **Review date** | `2026-08-04` (WQ9I-D dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0040a6e0_PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + caller `get_assembly_context` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Always constructs even when dest is null | **Falsified** — `TEST ECX,ECX` / `JZ` skips CALL |
| 2 | thiscall on placement itself (ECX=this) | **Falsified** — formals on stack; ECX only loaded from Stack dest for leaf handoff |
| 3 | RET 4 / stdcall cleanup of formals | **Falsified** — bare `C3` + parent `ADD ESP,8` |
| 4 | Width not 0x138 / different leaf | **Falsified** — sole callee dualed `00408880` width 0x138; parents stride +0x138 |
| 5 | Tree / freelist / CNDHash identity | **Falsified** — pure POD placement; no hash strings/fields |
| 6 | Scaffold SendLogicUi chain name is product identity | **Falsified** — plate only; rename to placement |
| 7 | Runtime Confirmed / bit-exact | **Fails** — open; no Launcher |

---

## 2. Decisive machine dataflow

```text
// formals after SEH:
// [ESP+0x14] = dest, [ESP+0x18] = src  (relative to post-SEH stack)
MOV ECX, [ESP+0x14]       // dest
MOV [ESP], ECX
MOV [ESP+0xC], 0          // EH scope
TEST ECX, ECX
JZ  skip
MOV EAX, [ESP+0x18]       // src
PUSH EAX
CALL 0x00408880           // leaf thiscall RET 4
skip:
MOV [ESP+0xC], -1
// restore FS:[0]
ADD ESP, 0x10
RET                       // C3 — not RET 8
```

Wrapper `FUN_00409f10`:

```text
MOV EAX, [ESP+8]   ; src
MOV ECX, [ESP+4]   ; dest
PUSH EAX
PUSH ECX
CALL 0040a6e0
ADD ESP, 8
RET 8
```

A ≡ B on live decompile + entry/exit/gate bytes.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null gate + leaf call | **High** | Wrong construct semantics |
| cdecl vs thiscall formals | **High** | Wrong port ABI |
| Width 0x138 via leaf/parents | **High** | Wrong stride |
| Product English | **Open** | Naming only |
| Runtime | **Open** | — |

---

## 4. Surviving contract

```text
PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred:
  cdecl dest*, src*; bare ret
  if dest: PodCopyConstruct_Elem0x138(dest, src)  // thiscall RET4 leaf
  else: no-op
```

**Verdict:** **accept-with-gaps**
