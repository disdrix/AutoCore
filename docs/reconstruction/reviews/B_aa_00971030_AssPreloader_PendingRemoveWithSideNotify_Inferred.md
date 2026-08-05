# Review B (skeptical / adversarial): `aa_00971030` AssPreloader_PendingRemoveWithSideNotify_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971030` |
| **VA** | `0x00971030` |
| **Canonical name** | `AssPreloader_PendingRemoveWithSideNotify_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W36-D) |
| **Counterpart** | `reviews/A_aa_00971030_AssPreloader_PendingRemoveWithSideNotify_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Decompiler `FUN_00970b20(param_1); FUN_0043e630(param_2)` thiscall plate? | **Incomplete** — first call ECX=key, stack=preloader; second ESI=preloader+0x1C, stack=key |
| Is pending offset +0x6c (cache preloader slot)? | **No** — bytes `ADD ESI,0x1C` only |
| Is this PushKeyFlag1 path? | **No** — calls `00970b20` (flag0), not `00970b60` |
| Could erase run before notify? | **No** — call order sealed |
| Is RET 0? | **No** — `C2 04 00` |
| Scaffold VOG_DEBUG name? | **Reject** — structural AssPreloader name from nested duals + caller |
| Same as EraseFirstEqual itself? | **No** — composite 30 B wrapper |

---

## Residual risks

1. Product event meaning of flag0.  
2. No assertion that key holder layout is single u32 (inherited from W33-N).  
3. Runtime / bit-exact.

---

## Minimal sealed model

```
AssPreloader_PendingRemoveWithSideNotify(preloader@ECX, key*@stack):
  SideHost_PushKeyFlag0(key*, preloader)   // host+0xAC push {key,0}
  GuardedVector_EraseFirstEqual(preloader+0x1C, key*)
  ret 4
```

---

## Verdict

Composite sealed; do not trust bare decompiler thiscall plate. **accept-with-gaps**.
