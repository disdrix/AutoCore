# Review B (skeptical / adversarial): `aa_00746400` StdVector_FindOrPushBackDword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00746400` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-V) |
| **Counterpart** | `reviews/A_aa_00746400_StdVector_FindOrPushBackDword_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Ghidra sig `undefined FUN_00746400(void)` is authoritative | **Falsified** — decompile + bytes: thiscall + stack value + `RET 4` + EAX returns |
| 2 | Return 0 means failure | **Falsified** — water caller treats only `hr < 0` as fail; 0 = newly appended OK |
| 3 | Free function with only stack args | **Falsified** — `MOV EAX,ECX`; callers load `DAT_00d1f620` into ECX |
| 4 | Decompiler `FUN_004406e0()` has no args | **Partial** — true as C; customcc EAX=vec ESI=&value sealed by bytes + dual of `004406e0` |
| 5 | Phase-token-only registry | **Weak** — water/distort use tokens; bootstrap callers push other 0x20 objects; unit is **generic** find-or-push |
| 6 | Scaffold `Named_CalleeOf_*` plate | **Reject** — structural `StdVector_FindOrPushBackDword_Inferred` matches sealed CF |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 4 + returns 0/1 | **High** | Wrong ABI |
| Vector begin/end + dword stride | **High** | Wrong layout |
| Push callee identity | **High** | Wrong growth path |
| `DAT_00d1f620` as common host | **High** | Wrong global (still generic API) |
| Product host English | **Low** | Naming |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

- Full 56 B hex ends `C2 04 00` (both exit paths).
- Body range Ghidra `00746400–00746437` matches hex length.
- Call-site pattern repeated: `8B 0D 20 F6 D1 00; 50; E8 …` → ECX=`[DAT_00d1f620]`, push value.
- Callee dual already filed as `StdVector_PushBackDword_Inferred` (layout +4/+8/+c).
- Xrefs: 5 sites — water, distort twin, two bootstrap once-gets, gfx init.

---

## 4. Surviving contract for AutoCore

```
// Port as generic dword vector find-or-push (not water-specific):
uint32_t FindOrPushBackDword(VecDword *vec /*this*/, uint32_t value) {
  for (uint32_t *p = vec->begin; p != vec->end; ++p)
    if (*p == value) return 1;
  PushBackDword(vec, &value); // FUN_004406e0 customcc
  return 0;
}
// Callers may bind this = *DAT_00d1f620. Do not treat 0 as error.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, scan, push path, returns, and generic container role. Product host English residual does not block. **accept**.
