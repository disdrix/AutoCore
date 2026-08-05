# Review B (skeptical / adversarial): `aa_0051a0e0` MedalDef_LookupById

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a0e0` |
| **VA** | `0x0051a0e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0051a0e0_MedalDef_LookupById.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** — CF sealed; table English Probable not High |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Thiscall with ECX table | Body sets `ECX=0x00b042e0` itself; arg on stack | **Falsified thiscall** — **cdecl** |
| 2 | Unsigned wrap for large ids | `TEST ESI / JL` treats high bit as null | **Survives signed gate** |
| 3 | Always hits hash | Empty table after lazy load returns null | **Falsified always** |
| 4 | Only medals use this table | Name from toast/award context only | **Survives Probable** |
| 5 | Lazy load always succeeds | Second count check can still fail | **Falsified** |
| 6 | Stub / trivial | Has load side effect | **Not pure** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF + globals addresses | **High** | Wrong table |
| cdecl arity | **High** | Stack bugs |
| Medal English | **Probable** | Misnamed system |
| Loader completeness | **Open** | Empty table forever if load broken |

---

## 3. Surviving contract for AutoCore

```
// Free function cdecl — not a method.
// Treat id -1 from objective templates as "no medal" before call when possible.
// Do not skip lazy-load path when porting cold-start clients.
```

## 4. What would overturn

1. Second hash root for "true" medals.
2. Strings proving table is another def class.
