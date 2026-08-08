# Review B (skeptical / adversarial): `aa_0090c700` MedalUI_PrepClearButtonSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090c700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-102) |
| **Counterpart** | `reviews/A_aa_0090c700_MedalUI_PrepClearButtonSlots_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This awards / grants medals | **Falsified** — no `FUN_0051a0e0` / no notify / no dirty bits; pure slot teardown |
| 2 | This is the full medal UI rebuild | **Falsified** — parent `FUN_0090cbc0` continues with count + `FUN_0090c9a0` bind |
| 3 | ECX-thiscall host | **Falsified** — body uses **EDI**; ECX only set for nested host vcalls; caller `MOV EDI,ESI` |
| 4 | `unaff_EDI` is phantom / unused garbage | **Falsified** — `LEA ESI,[EDI+0x540]` is first real use; storage `register:EDI` in analyze |
| 5 | Decompiler `+0x150` is byte offset 0x150 | **Falsified** — dword index: `0x150*4 = 0x540` sealed by `8D B7 40 05 00 00` |
| 6 | Always detaches via `+0xb0` | **Falsified** — gated on `vtbl[+0x3d8]` AL ≠ 0 |
| 7 | Scalar dtor flags=0 (release only) | **Falsified** — `PUSH 1` before `CALL [EDX]` |
| 8 | Frees the host / is host dtor | **Falsified** — bare `RET`; only nulls slots; host lives |
| 9 | Stack args / `RET 4` | **Falsified** — bare `C3`; no formals |
| 10 | Scaffold "CalleeOf VOG_DEBUG_STOP" is product role | **Falsified** — no strings here; VOG logs are parent hash-traversal error path |
| 11 | Same as `FUN_0090c750` zero-init | **Falsified** — `0090c750` writes zeros without detach/dtor; this unit deletes live widgets |
| 12 | Multiple static callers | **Falsified** — single xref `0090cbef` UNCONDITIONAL_CALL |
| 13 | Classification "leaf" means no side effects | **Falsified** — leaf in analyze = no static callees; virtual detach/delete are real effects |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI EDI-host / bare RET | **High** | Wrong call convention → crash |
| Slot base +0x540 × 24 | **High** | Wrong array / partial clear |
| vtbl +0x3d8 / +0xb0 | **High** | Wrong detach contract |
| Scalar flags=1 | **High** | Leak if ported as flags=0 |
| Prep-before-rebuild role | **High** | Wrong lifecycle order |
| Product host class English | **Low** | Naming only |
| Widget type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

| Check | Result |
|---|---|
| Live decompile 2026-08-05 ≡ raw 2026-07-23 CF | **Match** |
| Body size 77 B to RET | **Match** (`0x0090c700`–`0x0090c74c`) |
| Hex vs disasm mnemonics | **Match** |
| Caller seeds EDI | **Match** (`0x0090cbed MOV EDI,ESI`) |
| Parent writes slots via `unaff_ESI[unaff_EBX+0x150]` in `FUN_0090c9a0` | **Match** same `+0x540` family |
| Sibling XML `i_d_a_2d_btn_achievement.xml` | **Medal/achievement UI** context sealed without inventing product class name |

---

## 4. Surviving contract for AutoCore

```
// Before rebuilding medal achievement buttons:
//   EDI = medalUiHost;
//   MedalUI_PrepClearButtonSlots_Inferred();  // clears host+0x540[24]
// Then count (0090c810) and bind (0090c9a0) residual siblings.
// Do NOT treat as medal grant, host dtor, or ECX-thiscall.
```

---

## 5. Verdict

Adversarial attacks on grant/dtor/ECX/byte-offset/always-detach/scaffold-product claims **fail**. Residual product English only → **accept-with-gaps**. Terminal **false**.
