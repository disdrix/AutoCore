# Review A (reconstruction fidelity): `aa_0085fcc0` Client_UI_InventorySheet_RemoveByCoid

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085fcc0` |
| **VA** | `0x0085fcc0` |
| **Canonical name** | `Client_UI_InventorySheet_RemoveByCoid` (**INFERRED**) |
| **Prior names** | `FUN_0085fcc0`, `Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_0085fcc0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (raw ≡ live decompile ≡ entry/epilogue bytes) |
| **Counterpart** | `reviews/B_aa_0085fcc0_Client_UI_InventorySheet_RemoveByCoid.md` |
| **System** | `inventory-transfer` (UI sheet, not grid stamp) |
| **Live re-decompile** | Ghidra MCP `decompile_function` + `read_memory` @ `0x0085fcc0` / callees / call sites |
| **Verdict** | **accept-with-gaps** — ABI, COID key, hash pull, sheet detach, count-- **sealed**; vfunc `+0x3ac` product name + free ownership still Probable |

---

## 1. Purpose

**Remove one inventory-sheet UI entry keyed by instance COID** (`lo`,`hi`).

Given **ESI = inventory sheet host** and stack COID pair:

1. Fail soft if `*(sheet + 0x570) == 0` (no COID hash / list host).
2. `FUN_00413a60(coidLo, coidHi, &outWidget)` with **EDI = `*(sheet+0x570)`** — hash lookup + **unlink node**; outs the held UI widget pointer (node field `[3]`).
3. If widget non-null:
   - `widget->vtbl[+0x3ac]()` (thiscall) → cookie used for selection clear.
   - `FUN_007fbb70` with **EAX = `DAT_00d1a840`**, **EDX = cookie** — may clear UI selection if cookie matches current selectee.
   - `sheet->vtbl[+0xbc](widget)` — detach/remove widget from sheet UI.
   - `*(i32*)(sheet + 0x500) -= 1` — tracked item count.

**Does not** send C2S, **does not** call `InventoryGrid_RemoveItem` / `PlaceItemFootprint`, **does not** mutate cargo/locker cell arrays. UI sheet bookkeeping only (pair with add helper `0x008605b0`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0085fcc0_FUN_0085fcc0.md` |
| Annotated | `docs/reconstruction/raw/aa_0085fcc0_FUN_0085fcc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0085fcc0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0085fcc0_FUN_0085fcc0.md` |
| Live body | Ghidra decompile `0x0085fcc0` (CF matches raw; ESI/EDI register roles need bytes) |
| Entry / epilogue | `read_memory` `0x0085fcc0`… → **`ret 0x08`** (`c2 08 00`) |
| Thin wrapper | `FUN_0085fd20` @ `0x0085fd20` — `push item[+0x164], item[+0x160]; call` |
| Parent dual | `A_/B_aa_008c2940_UI_InventorySheet_RemoveItemByCoid.md` (loads ESI=`[ecx+0x580]`) |
| Add twin | `FUN_008605b0` — hash insert + `sheet[0x140]++` + vtbl `+0xa8` |
| Hash remove | `FUN_00413a60` (EDI = table; node out via `param_3`) |
| Selection clear | `FUN_007fbb70` (`DAT_00d1a840` host) |
| Callers | `FUN_00810670`, `FUN_0085fd20`, `FUN_008c2940` (+ wrapper xrefs into equip/sell paths) |

**Not performed:** `disassemble_bytes` (project RE rule), Launcher, live UI capture, bit-exact EXE diff.

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **ESI** | Inventory **sheet host*** | All body accesses `[esi+…]`; callers set ESI before CALL |
| stack0 | `uint32_t coidLo` | `Stack[0x4]`; wrapper / `008c2940` push `item+0x160` |
| stack1 | `uint32_t coidHi` | `Stack[0x8]`; push `item+0x164` |
| **EDI** (callee setup) | Hash table* = `*(ESI+0x570)` | Prolog `mov edi,[esi+0x570]`; `FUN_00413a60` uses `unaff_EDI` |
| return | void (EAX unused) | No post-call `test al` at sealed sites |
| cleanup | **`ret 0x08`** | Epilogue `c2 08 00` → **stdcall 2 stack dwords** |

```c
// Custom register + stdcall (not pure thiscall)
void __stdcall Client_UI_InventorySheet_RemoveByCoid(
    uint32_t coidLo,
    uint32_t coidHi);
// ESI = InventorySheetHost*  (caller-owned)
```

### 3.1 Entry bytes (authoritative)

```text
0085fcc0  push ecx                 ; shadow for local widget*
          push edi
          mov  edi, [esi+0x570]    ; hash host
          test edi, edi
          jz   epilogue            ; soft no-op
          mov  ecx, [esp+0x10]     ; coidHi (after 2 pushes)
          mov  edx, [esp+0x0c]     ; coidLo
          lea  eax, [esp+4]        ; &local_widget
          push eax
          push ecx
          push edx
          mov  dword [esp+0x10], 0 ; *local_widget = 0
          call FUN_00413a60
          mov  edi, [esp+4]        ; widget*
          test edi, edi
          jz   epilogue
          mov  eax, [edi]
          mov  ecx, edi
          call dword [eax+0x3ac]   ; thiscall → cookie in EAX
          mov  edx, eax
          mov  eax, 0x00d1a840     ; DAT_00d1a840 selection host
          call FUN_007fbb70
          mov  edx, [esi]
          push edi
          mov  ecx, esi
          call dword [edx+0xbc]    ; sheet detach(widget)
          add  dword [esi+0x500], -1
epilogue: pop  edi
          pop  ecx
          ret  8
```

Decompiler `unaff_ESI[0x15c]` ≡ dword index `0x15c` → byte offset **`0x570`**.  
Decompiler `unaff_ESI[0x140]` ≡ **`0x500`**.

---

## 4. Control flow: live ≡ raw

| Stage | Match |
|---|---|
| Gate `*(ESI+0x570) != 0` | **Yes** (bytes `test edi`) |
| Zero out widget local | **Yes** |
| `FUN_00413a60(lo,hi,&widget)` | **Yes** |
| Null widget → skip body | **Yes** |
| Widget vtbl `+0x3ac` thiscall | **Yes** (`mov ecx,edi; call [eax+0x3ac]`) |
| `FUN_007fbb70(DAT_00d1a840, cookie)` | **Yes** (`mov edx,eax; mov eax,imm; call`) |
| Sheet vtbl `+0xbc(widget)` | **Yes** |
| `*(ESI+0x500)--` | **Yes** (`add dword [esi+0x500], -1`) |
| `ret 8` | **Yes** |

---

## 5. Callees (body-backed)

### 5.1 `FUN_00413a60` — COID hash remove + out widget

- **EDI** = hash table (`*(sheet+0x570)`).
- Lookup via `FUN_00419b80(coidLo, coidHi)`.
- On hit: `*out = node[3]` (object/widget), zero node slot, unlink DLL, pool node, `table.count--`.
- Returns `0` / `0x80004005` (HRESULT-ish); **this unit ignores return**, uses out pointer only.
- Debug strings: `"HashError:remove, already locked for traversal"`.

### 5.2 Widget vtbl `+0x3ac`

- Thiscall on resolved sheet widget.
- Return value is **cookie** for selection compare (fed as EDX into `FUN_007fbb70`).
- Product name open (unbind / get-select-key / release-visual — **Probable** family).

### 5.3 `FUN_007fbb70` — conditional UI selection clear

```text
// EAX = DAT_00d1a840 (static/UI root object; image BSS zeros at rest)
// EDX = cookie from +0x3ac
if (cookie == 0 || *(EAX+0x309c) == 0 || cookie == *(*(EAX+0x309c)+0x518)) {
  *(u8*)(EAX+0x30b4) = 1;
  *(u8*)(EAX+0x30b5) = 0;
  if (sel = *(EAX+0x309c)) sel->vtbl[+4](0);
}
```

Clears selection **only when** the removed widget’s cookie matches current selectee (or no selectee / null cookie).

### 5.4 Sheet vtbl `+0xbc(widget)`

- Thiscall on **sheet host** (`ESI`), stack arg = widget.
- Symmetric to add path’s sheet vtbl **`+0xa8(widget)`** in `FUN_008605b0`.
- Role: remove child / unbind UI slot (**High**); whether it also `delete`s the widget **Open**.

---

## 6. Offsets (sheet host, sealed)

| Offset | Index (dword) | Role | Evidence |
|-------:|--------------:|------|----------|
| `+0x570` | `0x15c` | COID hash table* | gate + EDI for `00413a60` |
| `+0x500` | `0x140` | tracked UI item count | `--` after detach |
| vtbl `+0xbc` | — | remove/detach widget | call after clear |
| vtbl `+0xa8` | — | add twin attach | `FUN_008605b0` only |

Item COID (callers / wrapper):

| Offset | Role |
|-------:|------|
| `item+0x160` | COID lo |
| `item+0x164` | COID hi |

Matches grab/drop TFID/COID pair family used across inventory duals.

---

## 7. Callers (ESI sheet seal)

| Site | Function | How ESI / args are set |
|------|----------|------------------------|
| `0x008c295d` | `UI_InventorySheet_RemoveItemByCoid` | `ESI = [ECX+0x580]`; push `item+0x164/+0x160` |
| `0x0085fd2e` | `FUN_0085fd20` thin wrapper | EAX=item → push `+0x164/+0x160`; **ESI unchanged** (caller must set) |
| `0x0081082a` | `FUN_00810670` (sell/loot UI path) | `ESI = [*(client+0x105c)+0x5ac]`; push packet COIDs |
| via wrapper | `FUN_00810670` @ `0x00810949` | `ESI = [host+0x5ac]`; `EAX = item` → `0085fd20` |
| via wrapper | `FUN_007fee30`, `FUN_0093d6e0`, `FUN_00944d50` | same pattern: set ESI sheet, EAX item |

### 7.1 Thin wrapper `FUN_0085fd20` (bytes)

```text
mov ecx, [eax+0x164]
mov edx, [eax+0x160]
push ecx
push edx
call FUN_0085fcc0
ret
```

---

## 8. Pair with add helper `0x008605b0`

| Step | Remove (`0085fcc0`) | Add (`008605b0`) |
|------|---------------------|------------------|
| Hash | `00413a60` remove by COID | `00413920` insert |
| Sheet vtbl | `+0xbc` detach | `+0xa8` attach |
| Count `+0x500` | `--` | `++` |
| Widget | looked up | `operator_new` + `FUN_0085e590` ctor |

Symmetric inventory **sheet UI** list, not grid cells.

---

## 9. Confidence

| Claim | Level |
|---|---|
| stdcall 2 × COID + ESI sheet | **Confirmed** |
| Gate / hash at `+0x570` | **Confirmed** |
| Count `--` at `+0x500` | **Confirmed** |
| No grid / C2S mutation in body | **Confirmed** |
| COID ≡ `item+0x160/+0x164` | **Confirmed** (callers) |
| `+0x3ac` exact product meaning | **Probable** |
| `+0xbc` destroys vs detaches only | **Probable / Open** |
| `DAT_00d1a840` type name | **Tentative** (selection host) |
| Runtime / bit-exact | **Open** |

**Overall:** **accept-with-gaps.**
