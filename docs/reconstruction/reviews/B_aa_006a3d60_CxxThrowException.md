# Review B (skeptical / adversarial): `aa_006a3d60` _CxxThrowException

| Field | Value |
|---|---|
| **Stable ID** | `aa_006a3d60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W17-N dual seal) |
| **Counterpart** | `reviews/A_aa_006a3d60_CxxThrowException.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Contains inlined throw / unwind logic | **Falsified** — 6-byte `jmp [IAT]` only |
| 2 | Game-specific exception wrapper | **Falsified** — standard CRT symbol + form |
| 3 | Decompiler recursive self-call is real CF | **Falsified** — artifact of modeling IAT jmp as call |
| 4 | “Jumptable” implies multi-target dispatch | **Falsified** — single absolute IAT slot |
| 5 | Must reverse CRT body at this VA | **Falsified** — trampoline; CRT target is separate |
| 6 | stdcall / two-arg contract is wrong | **Unlikely** — Ghidra CRT signature + MSVC norm; body has no frame to contradict |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Trampoline form | **High** | None for game ports |
| Name identity | **High** | Mislabel callee in other reviews |
| Domain isolation | **High** | Wasted RE on CRT |
| Static IAT target address | **Medium** | Only matters for live memory tools |

---

## 3. Cross-check against raw + bytes

```
006a3d60:  FF 25 D8 64 9C 00   ; jmp [0x009c64d8]
```

Clean plate must remain a **thin import shim**. Do not invent AutoAssault-specific throw policies at this address.

---

## 4. Surviving contract for AutoCore

```
// Identity only — use host language exceptions or CRT when porting throw sites.
// Do not reimplement MSVC EH at 0x006a3d60.
[[noreturn]] void _CxxThrowException(void* obj, ThrowInfo* info); // CRT
```

When documenting other units: report callees as `_CxxThrowException @ 0x006a3d60` (import) without expanding CRT internals unless separately tasked.

---

## 5. Open questions

1. Whether any delayed-import / bind-on-first-use path rewrites the IAT slot at runtime.
2. Optional: map `0x006ebcee` CRT region only if EH port needed (out of OWN scope for this dual).

**Verdict:** **accept**
