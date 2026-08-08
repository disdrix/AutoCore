# Review B (skeptical / adversarial): `aa_00427040` StdVector_DestroyRuns_0x80_Thunk_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00427040` |
| **VA** | `0x00427040` |
| **Canonical name** | `StdVector_DestroyRuns_0x80_Thunk_Inferred` |
| **Review date** | `2026-08-05` (R10-003) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00427040_StdVector_DestroyRuns_0x80_Thunk_Inferred.md` |
| **System** | skills-abilities / UI text-layout SEH alias |
| **Verdict** | **accept** — agree with A |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + assembly context (no `disassemble_bytes`). No Launcher.

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `thunk_FUN_004271c0` only | Scaffold OK; under-describes sealed role |
| Expanded parent body as local function | **Reject** — bytes are sole JMP; decompiler thunk-follow |
| Second independent vector tidy | **Reject** — no local loop/delete at this VA |
| thiscall ECX=vector | **Reject** — EBX inherited; parent uses EBX shell |
| Skills/ability product mutator | **Reject** — pure SEH JMP alias; no skill logic |
| Direct CALL site inventory for this VA | **Reject** — only Unwind JMP xrefs |
| `StdVector_DestroyRuns_0x80_Thunk_Inferred` | **Accept** — parent-aligned + Thunk; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Decompile body is local truth | **Fails** — `disassemble_function` sole `JMP 0x004271c0`; bytes `E9 7B 01 00 00` |
| Rel32 mis-target | **Fails** — `0x00427040+5+0x17B = 0x004271C0` |
| Callers are normal CALL | **Fails** — both sites `JMP`; Ghidra labels Unwind@… |
| EBX not set by Unwind | **Fails** — `MOV EBX,[EBP+4]; ADD EBX,0x80` immediately before JMP |
| Thunk is multi-insn trampoline (push/jmp) | **Fails** — single rel32 JMP, CC pad |
| Parent false-noreturn means no post-delete zero | **Fails** (parent dual) — bytes zero +4/+8/+0xC after delete |
| Product demangle proven here | **Fails** — open; keep `_Inferred` |

---

## 3. Cross-check against raw + bytes

```text
// THIS VA (OWN)
00427040: E9 7B 01 00 00     JMP 0x004271c0
00427045: CC…                pad

// SEH Unwind@009ac2fc
009ac2fc: MOV EBX, [EBP+4]
009ac2ff: ADD EBX, 0x80
009ac305: JMP 0x00427040

// SEH Unwind@009add3e
009add3e: MOV EBX, [EBP+4]
009add41: ADD EBX, 0x80
009add47: JMP 0x00427040

// Parent call site (not this VA; evidence)
00797dea: LEA EBX, [ESI+0x80]
00797df0: CALL 0x004271c0
```

Clean must **not** invent a second tidy body, thiscall, CALL-only inventory, or product demangle.

---

## 4. Agreement with Review A

- Pure JMP + EBX SEH alias + parent name family: **agree Confirmed**
- Name with `_Inferred`: **agree**
- Gaps (product English, FUN_00426f70 residual, runtime): **agree open**

---

## 5. Surviving contract for AutoCore

```csharp
// Port as pure alias of StdVector_DestroyRuns_0x80_Inferred:
// Same EBX-this vector tidy (begin@+4 end@+8 cap@+0xC; stride 0x80).
// Prefer calling the parent implementation once; this VA is SEH JMP alias only.
// Do not free host layout inside the tidy; do not invent skill product role.
```

Port may fold the thunk into a single `DestroyRuns0x80(vec)` helper — retail keeps a 5 B JMP for EH table density.

---

## 6. Residual risks

- Do not dual-count coverage as a separate tidy implementation.
- Do not merge with other stride vectors (dword / 0x18 / 0x28 / 0x38) without layout check.
- Parent product English residual remains (`_Inferred`).

**Verdict:** **accept**
