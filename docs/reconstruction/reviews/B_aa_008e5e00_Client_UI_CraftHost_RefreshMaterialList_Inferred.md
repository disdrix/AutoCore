# Review B (adversarial): `aa_008e5e00` Client_UI_CraftHost_RefreshMaterialList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e5e00` |
| **VA** | `0x008e5e00` |
| **Canonical name** | `Client_UI_CraftHost_RefreshMaterialList_Inferred` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Adversarial / falsification |
| **Counterpart** | `reviews/A_aa_008e5e00_Client_UI_CraftHost_RefreshMaterialList_Inferred.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks attempted

| # | Hypothesis | Result |
|---|------------|--------|
| 1 | ECX-thiscall like bind siblings | **Falsified** — entry uses **EDI** (`CMP [EDI+0x754]`); no `MOV reg,ECX` host load; callers never set ECX before CALL |
| 2 | Stack args / `RET n` | **Falsified** — exit is plain `RET` (`C3`); no `C2 xx 00` |
| 3 | Invalid test is `pair == -1` (decompiler) | **Falsified** — asm `AND EAX,EDX; CMP EAX,-1` → `(lo & hi) == -1` |
| 4 | Mission-UI-only helper (scaffold name) | **Falsified** — body fills craft host `+0x754` list from cargo/locker/equip and calls dualed craft-host TFID bind; mission parent is only one caller among craft-host refresh chain |
| 5 | Lists all inventory items | **Falsified** — cargo/locker require `+0x17c` bit 19 set (filter-in) |
| 6 | Bit 19 is sealed “Broken” product meaning | **Open** — parent dual labels Broken with filter-out; this unit filter-in. Do not seal product English |
| 7 | No rebind on selection change | **Falsified** — `FUN_008e5ce0(host,lo,hi)` stdcall when `vtbl+0x44c` pair differs |
| 8 | Locker always scanned | **Falsified** — requires `char+0xcbc` and `DAT_00d1b644+0xf5 != 0` |
| 9 | Equip path uses same grid walk | **Falsified** — TFID table `+0x5a0` + `CVOGReaction_ResolveObjectTarget` (call `0x004bae70`) |
| 10 | `[M]` is cargo, `[L]` is equip | **Falsified** — `read_memory`: equip uses `DAT_00a3af60="[M]"`; locker uses `DAT_00a3af64="[L]"`; cargo has no prefix |

---

## Residual risks

- Decompiler understates `FUN_007fbd30` args (asm EAX=list, ESI=`host+0x758`) and collapses `vtbl+0x44c` EDX:EAX pair — clean/annotated use assembly authority.
- `FUN_00522000` / equip capacity vs mask `i&0xff` interaction unowned.
- Bit-19 product English conflict with parent dual label.
- Second caller at `0x008e63f5` lives in sibling host op (not dualed here).

---

## Confirmations with A

- EDI-host + plain RET sealed.  
- `(lo&hi)==-1` + bound-object TFID fallback sealed.  
- Three inventory sources + `[M]`/`[L]` sealed.  
- Rebind via dualed `008e5ce0` sealed.  
- Dual verdict align: **accept-with-gaps**.
