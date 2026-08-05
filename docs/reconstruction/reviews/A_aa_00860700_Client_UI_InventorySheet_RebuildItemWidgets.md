# Review A (reconstruction fidelity): `aa_00860700` Client_UI_InventorySheet_RebuildItemWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860700` |
| **VA** | `0x00860700` |
| **Canonical name** | `Client_UI_InventorySheet_RebuildItemWidgets` |
| **Prior names** | `FUN_00860700`, `Named_CalleeOf_Client_RefreshOpenMissionUiWindows_00860700` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B) |
| **Reviewer role** | Independent reconstruction review (raw ≡ live ≡ entry bytes) |
| **Counterpart** | `reviews/B_aa_00860700_Client_UI_InventorySheet_RebuildItemWidgets.md` |
| **System** | `inventory-transfer` (UI sheet bulk refresh) |
| **Dual status** | **Present** (first dual seal) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Bulk rebuild** of inventory-sheet item widgets for the window in **ESI**.

```text
// Custom ESI-this (not pure thiscall):
//   ESI = inventory UI window / sheet host
//   plain RET

if (*(ESI + 0x56c) == 0) return;   // no type host / grid binder → no-op

// local COID list object (vtbl PTR_FUN_00a34140) + critsec
FUN_0085fd80()                     // clear existing sheet widgets / hash
FUN_00571260(&list, (char)ESI[0x159])  // page idx byte @ +0x564 → collect grid items
// iterate list:
//   while FUN_00413be0(cursor) == 0:   // next TFID/COID pair
//     item = CVOGReaction_ResolveObjectTarget(1, coidLo, coidHi)
//     if item: FUN_008605b0()          // EDI=ESI window, EBX=item (caller sets)
// teardown list / LeaveCriticalSection / FUN_00931d60
ESI->vtbl[+0x34c]()                // window dirty/refresh
// destroy local list + DeleteCriticalSection
```

**Not** a C2S packet. **Not** inventory model mutation. UI re-materialize only.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00860700_FUN_00860700.md` |
| Annotated | `docs/reconstruction/raw/aa_00860700_FUN_00860700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00860700.cpp` |
| Function record | `docs/reconstruction/functions/aa_00860700_FUN_00860700.md` |
| Live decompile | Ghidra `0x00860700` ≡ raw (`unaff_ESI` = window) |
| Live entry | `read_memory` `0x00860700` — SEH then `mov eax,[esi+0x56c]` gate |
| Call site of Add | `get_assembly_context` `0x008607b2`: `mov ebx,eax; mov edi,esi; call FUN_008605b0` |
| Child dual | `aa_008605b0` Client_UI_InventorySheet_AddItemWidget |
| Trade dual | `aa_008847f0` CDlgTrade2d_CreateChildWidgets calls this for grid refresh |

**Not performed:** `disassemble_bytes`, Launcher, full dual of `FUN_0085fd80` / `FUN_00571260`.

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **ESI** | inventory sheet window* | entry `[esi+0x56c]`; loop `mov edi,esi` for child |
| ECX | *not* this | Ghidra shows `unaff_ESI` |
| stack | none for this | plain ret after SEH |
| return | void | — |

Callers (from `get_function_callers`):

| Caller | Role |
|--------|------|
| `CDlgTrade2d_CreateChildWidgets` `0x008847f0` | trade UI grid refresh |
| `Client_RefreshOpenMissionUiWindows` `0x0093a940` | mission UI inventory panes ×N |
| `FUN_0088f790` / `FUN_0088f8e0` | UI open helpers |
| `FUN_008c2f50` / `008c2fe0` / `008c3080` / `008c3140` / `008c3b80` | cargo/locker/equip sheet family |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Gate `*(window+0x56c) != 0` | **Yes** — `0x56c` = index `[0x15b]` |
| Init local list + `InitializeCriticalSection` | **Yes** |
| `FUN_0085fd80` clear | **Yes** |
| `FUN_00571260(&list, pageByte)` | **Yes** — page from `ESI[0x159]` = `+0x564` |
| Iterate `FUN_00413be0` until non-zero | **Yes** |
| Resolve TFID → item; on hit `FUN_008605b0` | **Yes** |
| Window `vtbl+0x34c` refresh | **Yes** |
| List dtor + `DeleteCriticalSection` | **Yes** |

### Decompiler artifact

`unaff_ESI` is **intentional** custom convention (caller leaves sheet in ESI), not a decompiler bug. Entry bytes load `[esi+0x56c]` immediately after SEH setup.

---

## 5. Offsets (window ESI)

| Offset | Role | Conf |
|-------:|------|------|
| `+0x56c` | type host / grid binder (gate) | **High** (shared with Add/Drop/HitTest) |
| `+0x564` | page index byte (passed to collect) | **High** |
| vtbl `+0x34c` | UI refresh after rebuild | **High** CF |

Child path reuses sealed AddItemWidget: widget ctor `0085e590`, place `0085f150`, COID hash at `window+0x570`.

---

## 6. Confidence

| Claim | Confidence |
|---|---|
| Bulk rebuild = clear + collect page items + Add each | **High** |
| ESI window ABI | **High** |
| Gate on type host | **High** |
| Exact semantics of `FUN_0085fd80` / `FUN_00571260` | **Probable** (role from position; bodies not dualed here) |
| Product symbol | **Open** |
| Runtime | **Open** |

---

## 7. Gaps

1. Full dual of clear helper `FUN_0085fd80` and grid collect `FUN_00571260`.
2. Whether rebuild is always page-scoped only (collect takes page byte).
3. Window product class (cargo vs locker vs trade share offsets).

**Verdict:** **accept-with-gaps**
