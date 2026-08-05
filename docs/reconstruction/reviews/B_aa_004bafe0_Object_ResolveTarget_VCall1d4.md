# Review B (skeptical / adversarial): `aa_004bafe0` Object_ResolveTarget_VCall1d4

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bafe0` |
| **VA** | `0x004bafe0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bafe0_Object_ResolveTarget_VCall1d4.md` |
| **Evidence** | Adversarial re-read of decompile + image bytes; cross-check equip caller |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Free function with 3 args only (no this) | **Falsified** | ECX must be live for Resolve thiscall; no ECX setup in body → caller supplies ctx in ECX |
| 2 | Implements hash lookup itself | **Falsified** | Sole CALL is `ResolveObjectTarget` |
| 3 | Always returns object* from hash | **Falsified** | Returns **vfunc result**, not the resolve pointer (unless vfunc is identity) |
| 4 | Mutates equip hardpoints | **Falsified** | Pure call chain |
| 5 | Four stack args | **Falsified** | `ret 0x0c` |
| 6 | Same as `Object_ResolveFromTFID` | **Falsified** | Extra vcall `+0x1d4`; different plate/use |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Resolve + null gate + vcall | **High** (image) | Wrong vehicle pointer on equip |
| ECX = resolve ctx passthrough | **High** | Silent null resolves |
| Vfunc product role | **Open** | Mis-name only if not identity |
| Equip vehicle* contract | **High** CF / **Medium** type | Cast mismatch if vfunc ≠ vehicle |

---

## 3. Cross-check spine

```
Object_ResolveTarget_VCall1d4(ctx, bGlobal, lo, hi):
  obj = ResolveObjectTarget(ctx, bGlobal, lo, hi)   // ECX=ctx
  if !obj: return 0
  return obj->vtbl[+0x1d4]()
```

---

## 4. Surviving contract for AutoCore

```
ResolveTarget_VCall1d4(ctx, domain, idLo, idHi) -> ptr|null
  resolve TFID via dual-table helper; invoke object vfunc 0x1d4
  equip path: vehicle TFID → vehicle handle
  no mutation
```

---

## 5. Open questions

1. Product name / role of vtable `+0x1d4`.
2. Whether create-from-packet and equip share identical return semantics.

**Verdict:** **accept-with-gaps**
