# Review B (skeptical / adversarial): `aa_004d5c10` Mission_ProcessInteractOfferStaging

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d5c10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d5c10_Mission_ProcessInteractOfferStaging.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** — CF + ABI High; product English / residual register open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Decompiler arity wrong (like 004d08c0) | Epilogue `ret 0xC` + 3 call-site pushes | **Survives** — 3 formals **Confirmed** |
| 2 | Always fills rolled rewards | Type-0 path uses `FUN_004cf100`; 0x3a path may build empty vector | **Falsified always** |
| 3 | Is eval-only like `004d5aa0` | Writes staging + `FUN_004d08c0` / `FUN_004cf100` | **Falsified** — mutates |
| 4 | `operator_delete` noreturn aborts process | Shared epilogue after vector free; `ret 0xC` present | **Falsified** as process exit |
| 5 | Type `0x3a` means “mission giver NPC” in product | Only numeric compare sealed | **Open** English — **numeric Confirmed** |
| 6 | `unaff_EDI` is a real formal | Not in signature; decomp register junk | **Open** — do not invent formal |
| 7 | Sole purpose is offer | Also turn-in ready staging when `*param_2` set | **Partial** — offer **and** turn-in staging |
| 8 | Name sealed by strings | No product string in body | **Tentative** name only |
| 9 | Character indices `[0x14c]..[0x152]` wrong | Consistent with staging duals (`+0x508` map is different field; these are dword indices on char*) | **Survives** as decomp indices — map to byte offsets via `N*4` when porting |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `ret 0xC` / 3 args | **Confirmed** | Stack smash |
| Entry clear staging `0,-1` | **High** | Stale offers bleed |
| 0x3a vs type-0 split | **High** | Wrong reward pipeline |
| Staging field writes | **High** | Broken turn-in UI / grant |
| Offer vector construction details | **High** CF / **Medium** field English | Missed offers |
| param_3 semantics | **Medium** | Wrong roll feed |
| Product function name | **Medium** | Naming only |

---

## 3. Live ≡ raw

- Fresh `decompile_function` (2026-07-29) matches 2026-07-23 raw scaffold body (same stages, same callees, same gates).
- Entry SEH + arg0 load sealed by `read_memory`.
- Epilogue `add esp,0x44; ret 0xC` sealed by `read_memory` @ `0x004d64b8`.
- Call site @ `0x009245e6` targets this VA (relative call decode).

No evidence of missing major branch in clean vs raw.

---

## 4. Surviving contract for AutoCore

```
// MUST use 3-arg ret 0xC shape.
// MUST clear staging (0, -1) after character resolve before offer work.
// MUST gate rolled-reward path on target type dword == 0x3a.
// MUST keep type-0 path (FUN_004cf100) for non-0x3a hash hits.
// MUST NOT drop FUN_004d08c0 third arg (param_3) when porting rewards.
// unaff_EDI: do not invent; leave as unresolved third to CheckMissionRequirements
//   until that callee dual seals the formal.
// Pair with EvalOfferableMissionInteractState for UI state only — this unit stages.
```

---

## 5. Gaps that block “accept” without qualifier

1. Caller packet / product name unknown.
2. Type-id English open.
3. `unaff_EDI` residual.
4. param_3 live value distribution unknown.
5. Runtime golden open.

**Verdict:** **accept-with-gaps**.
