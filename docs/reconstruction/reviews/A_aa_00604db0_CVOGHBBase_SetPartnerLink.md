# Review A (reconstruction fidelity): `aa_00604db0` CVOGHBBase_SetPartnerLink

| Field | Value |
|---|---|
| **Stable ID** | `aa_00604db0` |
| **VA** | `0x00604db0` |
| **Canonical name** | `CVOGHBBase_SetPartnerLink` |
| **Review date** | `2026-07-29` (W20-S OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ bytes) |
| **Counterpart** | `reviews/B_aa_00604db0_CVOGHBBase_SetPartnerLink.md` |
| **System** | `object / combat-target / HB` |
| **Dual status** | **Present** |
| **Verdict** | **accept** |

---

## 1. Purpose

**Leaf partner-link setter** on a `CVOGHBBase`-family object:

```
if (partner == null || partner.owner(+0x18) != this.owner(+0x18))
    this.partner(+0x24) = partner;
```

Used by `Object_SetSelectedTarget` to cross-link the self-side `CVOGHBPlayerTargetingLink` and the target-side targeting HB after both are constructed (`new(0x28)` each).

**Calling convention:** MSVC `__thiscall` — HB in `ECX`, partner on stack. **`RET 4`**. Void.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw + W20-S append | `docs/reconstruction/raw/aa_00604db0_FUN_00604db0.md` |
| Annotated | `docs/reconstruction/raw/aa_00604db0_FUN_00604db0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBBase_SetPartnerLink.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_00604db0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00604db0_CVOGHBBase_SetPartnerLink.md` |
| Live re-decompile | Ghidra `decompile_function` @ `0x00604db0` — **≡ raw** |
| Bytes | `read_memory` 32 B @ `0x00604db0` — full CF sealed |
| Xrefs | only `Object_SetSelectedTarget` ×2 |
| Parent dual | `A_aa_005172d0_Object_SetSelectedTarget` documents both-ways call |
| Owner field | `CVOGHBBase_AttachOwnerObject` / `a_0051e3b0` — `+0x18` owner |

**Not performed:** `disassemble_bytes`, Launcher, runtime partner golden.

---

## 3. Byte seal (complete body)

| Bytes | Meaning |
|---|---|
| `8B 44 24 04` | `eax = partner` |
| `85 C0` / `74 08` | null → write |
| `8B 50 18` | `edx = partner[+0x18]` |
| `3B 51 18` / `74 03` | same owner → skip |
| `89 41 24` | `this[+0x24] = partner` |
| `C2 04 00` | `ret 4` |

Clean ≡ raw ≡ these bytes. No residual CF.

---

## 4. Control flow matrix

| Stage | Match |
|---|---|
| Null partner → store 0 | **Yes** |
| Non-null different owner → store | **Yes** |
| Non-null same owner → no write | **Yes** |
| No callees | **Yes** |
| `ret 4` | **Yes** |

---

## 5. Confidence table

| Area | Confidence | Notes |
|---|---|---|
| CF / ABI | **High** | full byte seal |
| `+0x24` partner | **High** | parent dual + body |
| `+0x18` owner | **High** | AttachOwner family |
| Same-owner skip motive | **Probable** | prevent same-owner overwrite |
| Product method name | **Tentative** | family inferred |
| Runtime golden | **Open** | |

---

## 6. Gaps / open

1. Product C++ symbol.
2. Runtime verify of both-ways link after target set.
3. Whether same-owner skip is ever hit outside theoretical misuse (only targeting caller observed).

**None block accept** — leaf is fully sealed.

---

## 7. AutoCore impact

When porting selected-target HB pairing:

- Cross-link partners at **`+0x24`**, not only store `entity+0xA0`.
- Gate writes: **clear always**; link only if **owners differ**.
- Do not skip the reverse link (`SetPartner` both directions at parent).
