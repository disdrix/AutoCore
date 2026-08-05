# Dual A/B report — `aa_006a3d60` _CxxThrowException

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x006a3d60`. Dual A/B + artifacts. Seal CRT import trampoline.  
**Agent:** W17-N OWN dual.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_006a3d60` _CxxThrowException | **accept** — **6-byte `jmp [IAT]` CRT trampoline sealed** |

---

## Sealed facts

1. **Role:** MSVC `_CxxThrowException` **import thunk** — not game logic.

2. **Body:** `0x006a3d60`–`0x006a3d65` — bytes **`FF 25 D8 64 9C 00`** = `jmp dword ptr [0x009c64d8]`.

3. **IAT:** slot `0x009c64d8` holds implementation pointer (static dump: `0x006ebcee`).

4. **ABI (CRT):** `noreturn void __stdcall _CxxThrowException(void *pExceptionObject, ThrowInfo *pThrowInfo)`.

5. **Decompiler noise:** “jumptable” / recursive self-call — ignore; single IAT jmp.

6. **Name:** product/CRT symbol already present — `_CxxThrowException`.

---

## Gaps

1. Live IAT bind may differ under alternate CRT loads.  
2. Full MSVC EH / ThrowInfo tables — out of scope for this thunk dual.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_006a3d60_CxxThrowException.md` |
| Review B | `docs/reconstruction/reviews/B_aa_006a3d60_CxxThrowException.md` |
| Function record | `docs/reconstruction/functions/aa_006a3d60_CxxThrowException.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CxxThrowException.cpp` |
| Raw | `docs/reconstruction/raw/aa_006a3d60_CxxThrowException.md` |
| Annotated | `docs/reconstruction/raw/aa_006a3d60_CxxThrowException.annotated.md` |
| Scratch | `tmp/a_006a3d60.md` |
| This report | `docs/agents/task-dual-ab-006a3d60-cxxthrowexception-report.md` |

---

## AutoCore impact

- Treat as **external CRT identity** when documenting throw sites.  
- Do not port or reimplement this VA as game code.  
- Server C# ports use language exceptions, not this trampoline.
