# Review B (adversarial): `aa_004c9120` Object_CacheAIProfileFields_TypeMask_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9120` |
| **VA** | `0x004c9120`–`0x004c92e3` |
| **Canonical name** | `Object_CacheAIProfileFields_TypeMask_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial / red-team (OWN-ONLY W27-H) |
| **Counterpart** | `reviews/A_aa_004c9120_Object_CacheAIProfileFields_TypeMask_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Attack surface

| Claim under test | Attack | Result |
|---|---|---|
| "Callers" are real CALL sites | Ghidra UNCONDITIONAL_CALL | **Nuanced** — bytes are **E9 JMP** MI adjustor thunks with DATA vtable xrefs; still valid entries, not ordinary CALL |
| False mid-body `C2` RET | scanner hit @ `0x004c924f` | **Rejected** — SSE/imm encoding noise; real epilogue only `5E 83 C4 08 C3` @ end |
| Same as `FUN_004c9430` | shared map pair | **Rejected** — sibling creates CVOGHB*; this only caches fields + type mask |
| void vs return value | analyze "undefined return" | **Rejected** — decompile void; plain `C3`; no EAX publish |
| Wrong map helper | could be +0x15 isnil map | **Rejected** — calls sealed `004cbd50` (isnil+0x65) |
| Fastcall vs thiscall | decompiler `__fastcall` | **Accept either label** — ECX this, 0 stack formals, callee-owned frame; sealed |

---

## 2. Residual risks (non-blocking)

- Decompiler omits explicit ECX pass into `FUN_005c8eb0` / map thiscall (known surface; bytes restore).
- Product field names open.
- No runtime.

---

## 3. Cross-check vs A

A's offset table and thunk story match `read_memory`. Map callee duals already accepted W26-N/O.

---

## 4. Verdict

Adversarial pass **confirms** A with thunk-classification clarification → **accept**.
