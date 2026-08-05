# Review A (reconstruction fidelity): `aa_0093d6e0` Client_InventoryGrabApplyToCursor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093d6e0` |
| **VA** | `0x0093d6e0` |
| **Canonical name** | `Client_InventoryGrabApplyToCursor` (proposed; NAMING_REGISTRY) |
| **Prior names** | `FUN_0093d6e0`, `Named_CalleeOf_Client_RecvInventoryGrabResponse_0093d6e0` |
| **Review date** | `2026-07-29` (dual A/B — OWN-ONLY) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0093d6e0_Client_InventoryGrabApplyToCursor.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Apply a grabbed / unequipped **item** onto the client **cursor hand** for a destination inventory window selected by **`invType`**.

```
clear client+0xc70
require local char (client+0xe98) and item (EAX)
switch (invType in DL):
  1/3/5 → resolve grid host + capacity counter from character/window graph
  2     → set item parent via vtbl+0x2ac(client+0xd34); refresh vehicle sheet (client+0x1078); return 0
  4     → resolve from client+0x105c garage/storage window (null → 0)
  default → 0
if (gridHost && capHost):
  if invType != 4:
    if InventoryGrid_FindItemByCoid(item.coid) → InventoryGrid_RemoveItem(item, qty, 0)
    FUN_0085fd20();  // sheet/layout residual
    *(capHost+0x500) -= 1
    item.vtbl+0x260(qty)   // set stack qty on cursor object
  item.vtbl+0x218(char clonebase)  // reparent / attach to character
  FUN_007fc270(...); Client_RefreshOpenMissionUiWindows(client)
  client+0x30b4=1; +0x30b5=0; optional *(client+0x309c).vtbl+4(0)
  FUN_00931d60(); return 1
return 0
```

**Not** the S2C packet demux — callers are `Client_RecvInventoryGrabResponse` (0x2035) and `Client_RecvInventoryUnequipNotify` (0x203E case invType=2).

---

## 2. Calling convention — **SEALED**

| Slot | Role | Evidence |
|------|------|----------|
| **EAX** | `Item*` (grab source / new stack / unequipped) | Prologue `mov edi, eax`; Grab sites `mov eax, edi/ebp` before call |
| **DL** | `uint8_t invType` | Prologue `movzx ecx, dl`; Grab: `mov dl, [ebx+0x18]`; body switch on that byte |
| stack0 | `Client*` | Prologue `push ebp; mov ebp, [esp+8]`; callers `push esi/edi` (client) |
| stack1 | `qty` (int) | Grab: `push [ebx+0x1c]`; Unequip case2: `push 1` |
| AL / EAX | `bool` success | `xor al,al` fail; success `return 1` |
| Epilogue | `ret 8` | Bytes `c2 08 00` — **two** stack dwords |

Decompiler `__fastcall` + `in_EAX` / `unaff_retaddr` is **noise** for the second stack arg / return path; live call sites seal the four-slot ABI above.

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0093d6e0_FUN_0093d6e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0093d6e0_FUN_0093d6e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0093d6e0.cpp` (+ scaffold alias) |
| Function record | `docs/reconstruction/functions/aa_0093d6e0_FUN_0093d6e0.md` |
| Live decompile | Ghidra `decompile_function` / `batch_decompile` `0x0093d6e0` (2026-07-29) |
| Live bytes | `read_memory` `0x0093d6e0` length 256 — prologue + `ret 8` |
| Callers | `get_function_callers` → `Client_RecvInventoryGrabResponse`, `Client_RecvInventoryUnequipNotify` |
| Call-site asm | `get_assembly_context` @ `0x00811d7c`, `0x00811d9b`, `0x00813d55` |
| Named callees | `InventoryGrid_FindItemByCoid` (`0x00571010`), `InventoryGrid_RemoveItem` (`0x00571b80`), `Client_RefreshOpenMissionUiWindows`, `FUN_00931d60` |

**Not performed:** `disassemble_bytes`, Launcher, live process, bit-exact image diff.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Clear `client+0xc70` | **Yes** — `mov byte [ebp+0xc70], 0` |
| Fail if `client+0xe98==0` or `item==0` | **Yes** — dual tests → `xor al,al; ret 8` |
| Switch invType 1..5 (default 0) | **Yes** — `lea esi,[ecx-1]; cmp esi,4; ja` + jump table |
| Case 1: char `+0x250→+0x2b0` grid; UI `client+0x1040→+0x50c→+0x580` cap | **Yes** (decompiler offsets) |
| Case 2: parent set `vtbl+0x2ac(client+0xd34)`; if `client+0x1078` → `FUN_008801b0`; **return 0** | **Yes** — special path, no success-1 |
| Case 3: char `+0xcbc` grid; UI `client+0x1034→+0x510→+0x580` | **Yes** |
| Case 4: require `client+0x105c`; grid `+0x588→+0x35c`; cap host `+0x5ac`; **skip** remove/qty block | **Yes** — `cmp dl,4` gate |
| Case 5: char `+0xce0`; UI `client+0x1050→+0x588` | **Yes** |
| Non-4: FindByCoid → RemoveItem; `FUN_0085fd20`; `--*(cap+0x500)`; `vtbl+0x260(qty)` | **Yes** |
| Always (on host ok): `vtbl+0x218(char_clonebase)`; refresh UI; flags `+0x30b4/+0x30b5`; `FUN_00931d60`; return 1 | **Yes** |
| Clean scaffold ABI labels | **Weak** — body CF matches; param names/in_EAX residual |

### 4.1 invType case map (body-backed)

| invType | Grid source | Capacity / sheet host | Notes |
|--------:|-------------|------------------------|-------|
| 1 | `*( *(char+0x250) + 0x2b0 )` | `*(*(*(client+0x1040)+0x50c)+0x580)` | personal / bag path |
| 2 | *(n/a — early UI path)* | `client+0x1078` vehicle sheet | returns **0** after refresh |
| 3 | `*(char+0xcbc)` | `*(*(*(client+0x1034)+0x510)+0x580)` | |
| 4 | `*(*(client+0x105c)+0x588)+0x35c` | `*(client+0x105c)+0x5ac` | no Find/Remove/qty; reparent only |
| 5 | `*(char+0xce0)` | `*(*(client+0x1050)+0x588)` | |

Product English for invType enum still open (wire docs partially cover grab `ucTypeFrom`).

---

## 5. Offsets (body-backed)

| Offset | Role | Evidence |
|--------|------|----------|
| client `+0xc70` | flag cleared at entry | store 0 |
| client `+0xe98` | local character | null gate |
| client `+0xd34` | arg to item `vtbl+0x2ac` (case 2) | case-2 body |
| client `+0x1078` | vehicle inventory sheet UI | case 2 + `FUN_008801b0` |
| client `+0x105c` | storage/garage UI (case 4) | null → 0 |
| client `+0x30b4` / `+0x30b5` | cursor/UI dirty pair | set 1 / 0 on success |
| client `+0x309c` | optional callback object `vtbl+4(0)` | null-checked |
| item `+0x160/+0x164` (`[0x58]/[0x59]`) | TFID/coid for FindByCoid | `in_EAX[0x58/0x59]` |
| item vtbl `+0x260` | set quantity | non-4 path |
| item vtbl `+0x218` | attach/reparent to char clonebase | success path |
| item vtbl `+0x2ac` | set parent/owner (case 2) | |
| cap host `+0x500` | decrement occupancy | `--` once |

---

## 6. Callers (3 UNCONDITIONAL_CALL)

| Site | Function | Setup |
|------|----------|--------|
| `0x00811d7c` | `Client_RecvInventoryGrabResponse` | `DL=[pkt+0x18]`; push qty=`[pkt+0x1c]`, client; `EAX=item` (resolved TFID path / fail-early apply) |
| `0x00811d9b` | same | after stack-split create path; same ABI |
| `0x00813d55` | `Client_RecvInventoryUnequipNotify` | invType switch case **2**: push `1`, client; `EAX=unequipped item*` (EBX) |

---

## 7. Naming

| Claim | Confidence |
|---|---|
| Role = grab/unequip → cursor apply by invType | **High / Sealed** |
| Canonical `Client_InventoryGrabApplyToCursor` | **Probable** (registry proposed; PDB unknown) |
| Case-2 is vehicle-sheet-only (return 0) | **High** |
| invType product strings | **Open** |

---

## 8. Gaps

- Product names for invType 1..5 and UI nodes `0x1040/0x1034/0x1050/0x105c`.
- Exact English for `FUN_0085fd20` / `FUN_007fc270` (cursor chrome).
- Whether server uses same invType numbering.
- Runtime / bit-exact open.

---

## 9. Verdict

**accept-with-gaps** — ABI, switch CF, success path, and callers sealed from live bytes + call sites. Product enum English residual only.
