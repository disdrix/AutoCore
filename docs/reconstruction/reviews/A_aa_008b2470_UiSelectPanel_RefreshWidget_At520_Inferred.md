# Review A (reconstruction fidelity): `aa_008b2470` UiSelectPanel_RefreshWidget_At520_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008b2470` |
| **VA** | `0x008b2470`–`0x008b24a8` |
| **Canonical name** | `UiSelectPanel_RefreshWidget_At520_Inferred` (Ghidra `FUN_008b2470`) |
| **Ghidra name** | `FUN_008b2470` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_008b2470_UiSelectPanel_RefreshWidget_At520_Inferred.md` |
| **System** | `interaction-activation` / client select-target UI refresh |
| **Verdict** | **accept-with-gaps** — CF + slot `+0x520` + vtbl `+0xfc` sealed; product English open |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

Twin of `aa_00893580`: **select-target UI panel refresh** for child widget at **panel+0x520**.

Sole caller: `Client_SelectTargetObject_Inferred` (`0x0093e120`) when `client+0x10a4` panel is non-null and `vfunc+0x3d8` is true.

| Item | This VA (`008b2470`) | Twin (`00893580`) |
|---|---|---|
| Widget offset | **`+0x520`** | **`+0x54c`** |
| Parent panel slot | `client+0x10a4` | `client+0x10b4` |
| Helper | `FUN_00837d50` | same |
| vfunc | `+0xfc` | same |
| Float | `0x3f000000` (0.5f) | same |

Register ABI: **`EDI` = panel**, **`EBX` = mode flag** (same as twin).

CF identical to twin with offset substituted:

```
if (*(EDI+0x520)==0) return;
FUN_00837d50();  // EAX=EBX, ESI=widget
ECX = *(EDI+0x520);
push 0.5f;
if (EBX) vtbl+0xfc(1…); else vtbl+0xfc(0, 0.5f);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record / raw / annotated / clean | `aa_008b2470_*`, `FUN_008b2470.cpp` |
| Live decompile | Ghidra `batch_decompile` `0x008b2470` |
| Entry bytes | `read_memory` 80 B — same shape as twin; imm `20 05 00 00` = `0x520` |
| Callers | sole: `FUN_0093e120` |
| Callees | `FUN_00837d50`; `vtbl+0xfc` |
| Twin dual | `A_aa_00893580_*` |

**Not performed:** dual `00837d50`; product names; runtime; Launcher.

---

## 3. Machine evidence

```
56                   push esi
8B B7 20 05 00 00    mov  esi, [edi+0x520]   ; only structural delta vs twin
85 F6                test esi, esi
74 2C                je   ret
8B C3                mov  eax, ebx
E8 …                 call FUN_00837d50
85 DB                test ebx, ebx
8B 8F 20 05 00 00    mov  ecx, [edi+0x520]
68 00 00 00 3F       push 0x3F000000
74 0C                je   zero_arm
… push 1 / call [eax+0xFC] …
… push 0 / call [edx+0xFC] …
```

Body length and control match twin; **do not merge VAs**.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Widget **`+0x520`** | **Confirmed** | both loads |
| Twin of `00893580` | **Confirmed** | byte-diff = offset only |
| Parent select UI path | **High** | sole caller dual |
| 0.5f + `vtbl+0xfc` | **Confirmed** | same as twin |
| Product English | **Open** | residual |
| Decompiler arity on nonzero arm | **Probable** | same assembly note as twin |

---

## 5. Control flow checklist

| Stage | Match |
|---|---|
| Null `+0x520` skip | **Yes** |
| Helper then branch EBX | **Yes** |
| `vtbl+0xfc` both arms | **Yes** |
| No world select / net | **Yes** |

---

## 6. Gaps

1. Product panel/widget/`+0xfc` names.
2. Dual `00837d50`.
3. EBX producer seal; runtime.

**Verdict:** **accept-with-gaps** — `+0x520` select-panel refresh sealed; English residual.
