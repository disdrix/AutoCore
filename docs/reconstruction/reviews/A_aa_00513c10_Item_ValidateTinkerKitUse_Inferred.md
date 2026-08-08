# Review A (reconstruction fidelity): `aa_00513c10` Item_ValidateTinkerKitUse_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513c10` |
| **VA** | `0x00513c10`–`0x00513cde` (**207 B** / `0xCF`) |
| **Canonical name** | `Item_ValidateTinkerKitUse_Inferred` |
| **Prior names** | `FUN_00513c10`; `Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_00513c10` |
| **Review date** | `2026-08-05` (MEGA-036 dual seal) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00513c10_Item_ValidateTinkerKitUse_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (A + B) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Tinkering Kit use validator** for a target inventory item under the local character.

Returns status **0..4** consumed by:

| Caller | VA | Role |
|---|---|---|
| `Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` | `0x0085ce20` @ `0x0085d2bb` | Mode-4 tooltip messages |
| gap / orphan gate body | `0x0085d767` | Allow only if code == 4 |
| `FUN_0085f660` | `0x0085f675` | Apply confirm / success-chance dialog |

Not a network transfer unit — pure predicate.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ MEGA-036 re-verify) | `docs/reconstruction/raw/aa_00513c10_FUN_00513c10.md` |
| Annotated | `docs/reconstruction/raw/aa_00513c10_FUN_00513c10.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Item_ValidateTinkerKitUse_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00513c10.cpp` |
| Function records | `docs/reconstruction/functions/aa_00513c10_*.md` |
| Live | Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context` (3 sites) + `read_memory` 208 B + callees `00513bc0` / `00521eb0` + dualed caller `0085ce20` |
| Cross dual | `A/B_aa_0085ce20_Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` (mode-4 string map) |
| Not performed | `disassemble_bytes`, Launcher, bit-exact, runtime CE |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `00513c10`–`00513cde`, 207 B | **High / Sealed** | disassemble_function + next peer `00513cf0` |
| `__thiscall` ECX=item, **RET 8** | **High / Sealed** | every exit `C2 08 00`; prologue `MOV ESI,ECX` |
| Stack: character, kit | **High / Sealed** | call sites `PUSH kit; PUSH char` / decomp `FUN_00513c10(DAT_00d1b6d8, kit)` with this=item |
| Kit RTTI `CVOGTinkeringKit` at callers | **High** | dualed `0085ce20` |
| Return 0/1/2/3/4 map | **High / Sealed** | dualed caller switch + strings |
| Broken bit19 @ `+0x17c` | **High** | same family as `Item_SetBroken` / stack eligibility |
| maxSlots @ def `+0x4b4` vs vtbl `+0x8c` | **High** | assembly CMP AX,DI / JL |
| kit level @ `+0xb0` → 4/2 | **High** | SETGE + LEA `[CL+CL+2]` |
| `FUN_00513bc0` category gate | **High** | sole non-vtbl callee before skill path |
| `FUN_00521eb0` skill tier | **High** | ECX=character; maps `+0x59b` |
| `character+0x6b4` bypass | **Probable** | `>=1` skips skill fail; product English open |
| Product PDB name | **Open** | `_Inferred` required |
| clean ≡ raw ≡ live CF | **High** | decompile text match + assembly order |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| kit == 0 → 3 | **Yes** |
| category `FUN_00513bc0` fail → 3 | **Yes** |
| Broken bit19 → 0 | **Yes** |
| curSlots >= maxSlots → 0 | **Yes** |
| character == 0 → 3 | **Yes** |
| tier < need && bypass < 1 → 1 | **Yes** |
| kitLevel >= need → 4 else 2 | **Yes** |
| All exits RET 8 | **Yes** |

### Closed form (sealed)

```text
if !kit or !categoryMatch(item,kit): return 3
if Broken(item): return 0
if slotCount(item) >= maxSlots(item.def): return 0
if !character: return 3
need = slotCount(item) + 1
if skillTier(character) < need and character[+0x6b4] < 1: return 1
return (kitLevel(kit) >= need) ? 4 : 2
```

---

## 5. ABI seal (assembly)

```text
00513c10  MOV EAX,[ESP+8]     ; kit
00513c17  MOV ESI,ECX         ; item
00513c21  RET 8               ; null kit → EAX=3
...
00513c54  RET 8               ; broken → EAX=0
00513c7c  RET 8               ; no slots → EAX=0
00513c8f  RET 8               ; null character → EAX=3
00513cbe  RET 8               ; skill fail → EAX=1
00513cd4  RET 8               ; 4 or 2
00513cde  RET 8               ; category fail → EAX=3
```

Call-site example (`0x0085d2bb`):
```text
MOV ECX, ESI          ; item
PUSH EAX              ; kit (CVOGTinkeringKit*)
PUSH EDI              ; character (DAT_00d1b6d8)
CALL 0x00513c10
CMP EAX, 4
```

---

## 6. Gaps

1. Product/PDB name (inferred from role + dualed strings + hint `Item_ValidateTinkerKitUse`).
2. Full dual of callees `FUN_00513bc0`, `FUN_00521eb0` (unowned here).
3. Product English for `character+0x6b4`, vtbl `+0x8c`, def `+0x4b4`.
4. Orphan caller body @ `0x0085d767` (not in a Ghidra function symbol).
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
