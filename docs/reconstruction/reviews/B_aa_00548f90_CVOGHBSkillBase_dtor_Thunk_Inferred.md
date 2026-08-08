# Review B (skeptical / adversarial): `aa_00548f90` CVOGHBSkillBase_dtor_Thunk_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00548f90` |
| **VA** | `0x00548f90` |
| **Canonical name** | `CVOGHBSkillBase_dtor_Thunk_Inferred` |
| **Review date** | `2026-08-05` (R13-006) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00548f90_CVOGHBSkillBase_dtor_Thunk_Inferred.md` |
| **System** | skills-abilities / CVOGHBSkillBase lifecycle |
| **Verdict** | **accept** — agree with A |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `disassemble_function` + callers/xrefs (no `disassemble_bytes`). No Launcher.

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `thunk_FUN_00578a60` only | Scaffold OK; under-describes sealed parent family |
| Expanded parent body as local function | **Reject** — bytes are sole JMP; decompiler thunk-follow |
| Second independent complete dtor | **Reject** — no local vtbl/delete/zero at this VA |
| Scalar deleting dtor (flags&1 free this) | **Reject** — free-this lives in callers (`00651190` / `00578de0`) |
| OnEnd / vector element walk | **Reject** — parent frees buffer only; OnEnd is `00578ac0` |
| Base dtor alias (`CVOGHBBase_dtor` thunk) | **Reject** — target is skill-base complete body, not `00508390` |
| Runtime Confirmed | **Reject** — no Launcher; Terminal false |
| `CVOGHBSkillBase_dtor_Thunk_Inferred` | **Accept** — parent-aligned + Thunk; `_Inferred` honest for thunk demangle |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Decompile body is local truth | **Fails** — `disassemble_function` sole `JMP 0x00578a60`; bytes `E9 CB FA 02 00` |
| Rel32 mis-target | **Fails** — `0x00548f90+5+0x0002FACB = 0x00578A60` |
| Callers are JMP-only SEH (EBX style) | **Fails** — xrefs are **UNCONDITIONAL_CALL** (shared scalar + Unwind) |
| Thunk is multi-insn trampoline (push/jmp) | **Fails** — single rel32 JMP, CC pad |
| This VA frees `this` | **Fails** — free-this only in scalar callers after return from complete path |
| Parent false-noreturn means no base tail | **Fails** (parent dual) — parent ends JMP base dtor |
| Product demangle proven here | **Fails** — open; keep `_Inferred` |
| Claim Runtime Confirmed | **Fails** — not claimed |

---

## 3. Cross-check against raw + bytes

```text
// THIS VA (OWN)
00548f90: E9 CB FA 02 00     JMP 0x00578a60
00548f95: CC…                pad

// Shared scalar caller (not OWN; evidence R12-001)
00651190: PUSH ESI
00651191: MOV  ESI, ECX
00651193: CALL 0x00548f90     ; → this thunk → complete dtor
00651198: TEST byte [ESP+8], 1
… optional operator_delete(this); RET 4

// Base scalar (not OWN; evidence R11-006) — direct parent CALL, not this thunk
00578de3: CALL 0x00578a60

// Parent complete body (not OWN; evidence R12-026)
00578a60 … JMP 0x00508390     ; CVOGHBBase_dtor
```

Clean must **not** invent a second complete-dtor body, free-this, OnEnd walk, or Runtime Confirmed.

---

## 4. Agreement with Review A

- Pure JMP + parent family name + `_Inferred` thunk demangle: **agree Confirmed**
- Gaps (product thunk demangle, parent field English residual, runtime): **agree open**
- Terminal **false**: **agree**

---

## 5. Surviving contract for AutoCore

```csharp
// Port as pure alias of CVOGHBSkillBase_dtor:
// Same __thiscall ECX=this complete body (vtbl restore, free skill fields, base tail).
// Prefer calling the parent implementation once; this VA is JMP alias only.
// Shared subclass scalar dtor may CALL this alias then free(this) on flags&1.
// Do not free this inside the thunk; do not merge with OnEnd clear 0x00578ac0.
```

Port may fold the thunk into a single `CVOGHBSkillBase_dtor(this)` helper — retail keeps a 5 B JMP for CALL/EH density.

---

## 6. Residual risks

- Do not dual-count coverage as a separate complete-dtor implementation.
- Do not confuse with base scalar `0x00578de0` (direct parent CALL) or shared scalar `0x00651190` (calls this thunk).
- Parent field-English residual remains open (R12-026 accept-with-gaps).

**Verdict:** **accept**
