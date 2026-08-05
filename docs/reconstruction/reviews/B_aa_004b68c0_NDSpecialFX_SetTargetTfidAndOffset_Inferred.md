# Review B (skeptical / adversarial): `aa_004b68c0` NDSpecialFX_SetTargetTfidAndOffset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b68c0` |
| **VA** | `0x004b68c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_004b68c0_NDSpecialFX_SetTargetTfidAndOffset_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Writes a quaternion at `+0x68` | Could be orient quat XYZW | **Falsified** — four integer TFID limbs; `004b75d0` feeds `Object_ResolveFromTFID((TFID_16*)(this+0x68))` |
| 2 | Network / packet serializer | Side-effecting send | **Falsified** — leaf stores only; no calls |
| 3 | Same as `FUN_004b73c0` host binder | Both touch identity-like fields | **Distinct** — `004b73c0` writes `+0x10` host ptr + `+0x18` TFID cache; this writes `+0x68` target TFID + `+0x80` float4 |
| 4 | Float4 at `+0x80` is always identity quat | Callers pass `DAT_00b047c0` | **Falsified as quat** — zeros, not `(0,0,0,1)`; treated as offset/aim base in update |
| 5 | Free function / cdecl | Stack-only | **Falsified** — ECX `this`; thiscall |
| 6 | Product name known | Scaffold chain name | **Holds as false** — `_Inferred` required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Field offsets `+0x68` / `+0x80` | **High** | FX aim target mis-wire |
| TFID vs quat at `+0x68` | **High** | ResolveFromTFID would blow up |
| Leaf no side effects | **Confirmed** | Over-port of networking |
| Class bucket NDSpecialFX | **High** (layout peer) | Wrong subsystem folder only |
| Exact float4 domain English | **Probable** | Cosmetics / aim residuals |

---

## 3. Cross-check against raw / live

```
void thiscall(this, t0,t1,t2,t3, float* o4) {
  *(u32*)(this+0x68)=t0; *(u32*)(this+0x6c)=t1;
  *(u32*)(this+0x70)=t2; *(u32*)(this+0x74)=t3;
  *(u32*)(this+0x80)=o4[0]; … *(u32*)(this+0x8c)=o4[3];
}
```

Live decompile ≡ raw capture ≡ clean scaffold CF. `DAT_00b047c0` = 16×`00`.

---

## 4. Surviving contract for AutoCore

```
// Leaf; no validation
NDSpecialFX_SetTargetTfidAndOffset_Inferred(fx, tfid[4], offset4);
// Precondition for meaningful 004b75d0: fx host +0x10 set, param map populated
```

Weapon fire path (High): resolve owner → copy owner TFID → zero offset → `FUN_004b75d0`.

---

## 5. Open questions

1. Non-zero offset producers (if any) beyond zero defaults.
2. Relationship of `+0x68` target TFID vs host cache `+0x18` from `004b73c0` (distinct slots — confirmed dual use in `004b75d0`).

**Verdict:** **accept-with-gaps**
