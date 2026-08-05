# Review B (skeptical / adversarial): `aa_004a6820` StdVector_ThrowTooLong_B_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a6820` |
| **VA** | `0x004a6820` |
| **Canonical name** | `StdVector_ThrowTooLong_B_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W36-Q) |
| **Counterpart** | `reviews/A_aa_004a6820_StdVector_ThrowTooLong_B_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Actually returns / fallthrough? | **No** — final `_CxxThrowException`; decompiler marks noreturn |
| Capacity / size calculator? | **No** — pure throw; parents already checked max |
| Same binary as `004540b0`? | **No** — different body/size/SEH/wrap path; same plate+ThrowInfo only |
| Drop-in replace `StdVector_ThrowTooLong`? | **Porting yes for effect**; **binary no** — do not assume identical stack/exception layout |
| Gameplay/VOG_DEBUG logic? | **No** — scaffold name only; container overflow helper |
| string plate different? | **No** — `read_memory` confirms identical `"vector<T> too long"` @ `0x00a15830` |

---

## Residual risks

1. Exact exception C++ type / what_message layout vs W19-B path.  
2. Only 4 static callers vs 100+ on A-path — coverage of 004a* cluster only.  
3. No runtime.

---

## Minimal sealed model

```
StdVector_ThrowTooLong_B_Inferred():
  SEH(LAB_009a11a2)
  msg = "vector<T> too long"
  exception::exception(); vtbls; copy msg
  _CxxThrowException(ex, DAT_00acc388)  // noreturn
```

---

## Verdict

Port as **shared Xlen throw** for the 004a* vector family; keep distinct from `004540b0` only if matching retail exception construction. **accept-with-gaps**.
