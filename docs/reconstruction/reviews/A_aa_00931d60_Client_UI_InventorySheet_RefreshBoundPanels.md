# Review A (reconstruction fidelity): `aa_00931d60` Client_UI_InventorySheet_RefreshBoundPanels

| Field | Value |
|---|---|
| **Stable ID** | `aa_00931d60` |
| **VA** | `0x00931d60` |
| **Canonical name** | `Client_UI_InventorySheet_RefreshBoundPanels` (inferred) |
| **Ghidra symbol** | `FUN_00931d60` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_00931d60_Client_UI_InventorySheet_RefreshBoundPanels.md` |
| **System** | `inventory-transfer` (UI sheet) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Thin sheet-side refresh dispatcher** after inventory UI mutation (rebuild / grab-apply):

```text
// Custom EDI-this (sheet window); plain ret

panelA = *(EDI + 0x1078)
if panelA != 0:
  if panelA->vtbl[+0x3d8]() != 0:    // visibility / "should refresh?" probe
    FUN_008800e0()                   // refresh inv chrome children (uses ESI=panel)

panelB = *(EDI + 0x105c)
if panelB != 0:
  if panelB->vtbl[+0x3d8]() != 0:
    FUN_0088ef70()                   // refresh bound secondary widgets / colors
```

No list walk, no hash, no packet, no grid math. Two optional child panel pointers on the window; each gated by virtual predicate `+0x3d8` before a specialized refresh helper.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00931d60_FUN_00931d60.md` |
| Annotated | `docs/reconstruction/raw/aa_00931d60_FUN_00931d60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00931d60.cpp` |
| Function record | `docs/reconstruction/functions/aa_00931d60_FUN_00931d60.md` |
| Live decompile | Ghidra `decompile` / `force_decompile` @ `0x00931d60` — **A ≡ B ≡ raw** |
| Live bytes | `read_memory` @ `0x00931d60` length 96 — `+0x1078` / `+0x105c` / vtbl `0x3d8` |
| Callee A | decompile `0x008800e0` — multi-slot `FUN_00862b70` + `FUN_0087d810` if global UI live |
| Callee B | decompile `0x0088ef70` — color/`vtbl+0x15c`/`+0x34c` on two subwidgets |
| Callers | `0x00860700` RebuildItemWidgets; `0x0093d6e0` InventoryGrabApplyToCursor |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EDI = sheet/window host | **High** | Callers set EDI; offsets on large UI object |
| Null-safe panel ptrs `+0x1078`, `+0x105c` | **High** | Bytes `83 BF 78 10 00 00 00` / `5C 10` |
| Gate = virtual call slot **`0x3d8`** | **High** | `FF 90 D8 03 00 00` |
| Non-zero AL → call refresh helper | **High** | `84 C0 74 …` |
| Helper `0x008800e0` / `0x0088ef70` | **High** (addrs) / **Probable** (English) | Bodies decompiled this pass |
| Order: 1078 first, then 105c | **High** | Sequential |
| Product panel type names | **Tentative** | No RTTI in this unit |
| Name RefreshBoundPanels | **Probable** | Role from CF + callers |

---

## 4. Control flow: clean ≡ raw ≡ force

| Stage | Match |
|---|---|
| Optional panelA probe + refresh | **Yes** |
| Optional panelB probe + refresh | **Yes** |
| No third panel | **Yes** |
| Dual A≡B | **Yes** |
| No inventory model writes | **Yes** |

### ABI / machine seal

```text
83 BF 78 10 00 00 00     cmp dword [edi+0x1078], 0
… call [vtbl+0x3d8] …
E8 …                     call FUN_008800e0   ; ESI loaded from panel
83 BF 5C 10 00 00 00     cmp dword [edi+0x105c], 0
… call [vtbl+0x3d8] …
E8 …                     call FUN_0088ef70
5E C3                    pop esi; ret
```

Callees expect **ESI = panel** (set `mov esi,[edi+…]` before call when probe succeeds).

---

## 5. Callee roles (this pass)

| VA | Behavior (summary) |
|---|---|
| `0x008800e0` | If `DAT_00d1b6d8` and panel `vtbl+0x3d8`, refresh up to 10 child slots via `FUN_00862b70` then `FUN_0087d810` |
| `0x0088ef70` | Theme color (dim if `DAT_00d1b6d8+0xcd0==0`); push color to widgets at panel `+0x5b4` / `+0x5b8` via `vtbl+0x15c` + refresh `+0x34c` |

Full dual of those helpers is **out of scope** (OWN-ONLY this VA).

---

## 6. Callers

| Caller | Role |
|---|---|
| `Client_UI_InventorySheet_RebuildItemWidgets` | After item widget rematerialize |
| `Client_InventoryGrabApplyToCursor` `0x0093d6e0` | After grab cursor apply |

---

## 7. Gaps

1. Product names / types of panels at `+0x1078` / `+0x105c`.
2. Exact English of vtbl+0x3d8 (IsVisible vs IsLive vs ShouldLayout).
3. Deep dual of `008800e0` / `0088ef70`.
4. Runtime when both panels null (no-op) vs one live.

**Verdict:** **accept-with-gaps** — dual-panel gate + callee VAs **sealed**.
