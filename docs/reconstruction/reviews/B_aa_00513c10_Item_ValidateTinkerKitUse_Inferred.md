# Review B (adversarial): `aa_00513c10` Item_ValidateTinkerKitUse_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513c10` |
| **VA** | `0x00513c10` |
| **Canonical name** | `Item_ValidateTinkerKitUse_Inferred` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Adversarial / falsification |
| **Counterpart** | `reviews/A_aa_00513c10_Item_ValidateTinkerKitUse_Inferred.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks attempted

| # | Hypothesis | Result |
|---|------------|--------|
| 1 | cdecl / no thiscall; ECX unused | **Falsified** — `MOV ESI,ECX`; all exits `RET 8`; callers set ECX=item before CALL |
| 2 | Stack order is kit, character (swapped) | **Falsified** — function reads `[ESP+8]` first as kit; dualed caller pushes kit then character so character is `[ESP+4]` after CALL entry; decomp `FUN_00513c10(DAT_00d1b6d8, kit)` matches |
| 3 | Returns bool only (0/1) | **Falsified** — EAX loaded with 0/1/2/3/4 immediates; callers `CMP EAX,4` and `switch` 0..3 |
| 4 | This is the gadget validator (`FUN_00513400`) | **Falsified** — different VA; gadget path uses `FUN_00513400` + `CVOGGadget` RTTI; this path uses `CVOGTinkeringKit` + this body |
| 5 | Scaffold `Named_CalleeOf_Skill_…` is product name | **Reject** — parent-string seed only; body has no strings; role is full validator not skill-only |
| 6 | Function sends tinker C2S / mutates item | **Falsified** — no packet builders; only reads flags/slots/skill; callees are pure checks |
| 7 | Return 0 always means “no slots” only | **Partial** — body also returns 0 on Broken; dualed UI re-checks Broken and prints dedicated string before code-0 message. Documented, not a CF error |
| 8 | `character+0x6b4` is skill tier itself | **Falsified as tier** — tier comes from `FUN_00521eb0`; `+0x6b4` is a separate `>=1` bypass. Product English still open |
| 9 | Decompiler `(kit+0xb0)!=0` checks kit level | **Falsified** — assembly is `LEA EBX,[EAX+0xb0]; TEST EBX` (address); level is `MOVSX EAX,word ptr [EBX]` at tail |
| 10 | Skill compare `maxSlots <= cur` is inverted | **Falsified** — `CMP AX,DI; JL continue` means continue only if cur < max; else return 0 (full) |
| 11 | Success code is 0 or 1 | **Falsified** — success is **4** (`SETGE`→1 → `2*CL+2` = 4); callers gate on `CMP EAX,4` |
| 12 | RET 4 (one stack arg) | **Falsified** — every exit `RET 8` / `C2 08 00` |

---

## Residual risks

- Clean C++ models `FUN_00521eb0` ECX bind via cast thunk — CF preserved, not byte-identical prologue.
- Unowned `FUN_00513bc0` / `FUN_00521eb0` may refine category/skill lexicon without changing this unit’s CF.
- Orphan xref @ `0x0085d767` sits outside a named Ghidra function; still a live `UNCONDITIONAL_CALL` with same ABI (CMP EAX,4 gate).
- Product name remains inferred (hint-aligned).

---

## Confirmations with A

- ABI ECX=item, stack character+kit, **RET 8** sealed.
- Status 0..4 map sealed via dualed `0085ce20` / `0085f660` strings.
- Broken / maxSlots / kitLevel / skill-tier stages sealed.
- Dual verdict align: **accept-with-gaps**.
- Runtime Confirmed: **not claimed**.

---

## Verdict

### **accept-with-gaps**

Adversarial path does **not** reject. Gaps are lexicon / PDB / unowned callees / runtime — not CF or ABI defects.
