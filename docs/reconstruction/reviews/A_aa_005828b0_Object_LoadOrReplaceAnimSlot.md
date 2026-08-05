# Review A (reconstruction fidelity): `aa_005828b0` `Object_LoadOrReplaceAnimSlot`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005828b0` |
| **VA** | `0x005828b0` |
| **Body span** | `005828b0`–`005829c6` (through `ret 0xC`) |
| **Canonical name** | `Object_LoadOrReplaceAnimSlot` (structural) |
| **Ghidra name** | `FUN_005828b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W18-C) |
| **Counterpart** | `reviews/B_aa_005828b0_Object_LoadOrReplaceAnimSlot.md` |
| **System** | `client::special-event` / visual anim |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Load or replace an animation slot on a visual host:**

1. Require controller at `this+0x24`.
2. If `slots[slotIndex]` at `this+0x2c+4*index` occupied → controller remove (`vtbl+0x10`), teardown (`FUN_0074eb20`/`FUN_0074ecf0`), `delete`, zero.
3. `operator_new(0x78)` + ctor `FUN_0074ed90` → store.
4. Resolve path (`FUN_00989e00`, cache `ECX=0x00d1eac8`) + load (`FUN_0074ee40`); fail if `< 0`.
5. Duration from `FUN_0079a110(DAT_00b04c74)` (`float` at `+0x238`); `FUN_0074e910(slot, 0, dur)`.
6. Write `flagByte` to `slot+0x4c`; controller add (`vtbl+0x0C`).
7. Return `1` / `0`.

Primary consumers: INC airlift special events load slots **1/2/3** with `obj_f_inc_mov_01_airlift_*.anm`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005828b0_FUN_005828b0.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_005828b0_FUN_005828b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_LoadOrReplaceAnimSlot.cpp` |
| Scaffold clean | `reconstructed-exact/FUN_005828b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005828b0_Object_LoadOrReplaceAnimSlot.md` |
| Live decompile | Ghidra @ `0x005828b0` + callees |
| Bytes | `read_memory` @ entry + epilogue; call-site ECX loads |
| Xrefs | 9 call sites in 3 functions (TeleportIn/Out + `FUN_00979310`) |

**Not performed:** `disassemble_bytes`, Launcher, runtime anim golden.

---

## 3. ABI seal (`read_memory` + call sites)

### Epilogue

```text
... 83 C4 0C    add  esp, 0xC     ; drop SEH frame
    C2 0C 00    ret  0xC          ; 3 stack dwords
```

Fail path also ends `xor eax,eax` + same `ret 0xC`.

### Prologue this

```text
8B F1           mov  esi, ecx     ; this = visual host
83 7E 24 00     cmp  dword ptr [esi+0x24], 0
```

### Call-site ECX (visual, not special-event shell)

| Caller | Bytes | ECX |
|--------|-------|-----|
| TeleportOut `@ 0097840e` | `8B 4E 10` | `[esi+0x10]` visual |
| TeleportIn `@ 00978f29` | `8B 4D 24` | `[ebp+0x24]` visual field |
| `FUN_00979310` `@ 00979517` | `8B 4F 10` | `[edi+0x10]` visual |

Args (all three airlift loads): `push flag(0)` ; `push path` ; `push slot(1|2|3)`.

| Claim | Evidence | Conf |
|---|---|---|
| thiscall + **3** stack args + **`ret 0xC`** | epilogue + pushes | **Confirmed** |
| `this` = visual object | call-site `mov ecx` | **Confirmed** |
| Controller gate `+0x24` | prologue cmp | **Confirmed** |
| Slot table `+0x2c + index*4` | decompile + `8B 44 BE 2C` family | **Confirmed** |
| Alloc size **`0x78`** | `6A 78` / `operator_new` | **Confirmed** |
| Success **1** / fail **0** | `B8 01…` / `33 C0` | **Confirmed** |
| Live decompile ≡ raw CF | side-by-side | **Confirmed** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = load/replace anim slot | **Confirmed** | path `.anm` + controller add/remove |
| Replace-before-alloc order | **Confirmed** | decompile order |
| Load fail → return 0 (after store?) | **High** | store happens before load; orphan slot on fail is raw CF |
| Flag at `slot+0x4c` | **Confirmed** | `88 48 4C` after load |
| Duration global `DAT_00b04c74+0x238` | **High** | `mov ecx,[00b04c74]` + `FUN_0079a110` |
| Product type English | **Open** | structural name only |
| Controller vtbl slot English | **Open** | offsets sealed |

---

## 5. Call graph (this unit)

**Callees:** `operator_new`, `operator_delete`, `FUN_0074ed90`, `FUN_0074eb20`, `FUN_0074ecf0`, `FUN_00989e00`, `FUN_0074ee40`, `FUN_0079a110`, `FUN_0074e910`, controller `+0x0C`/`+0x10`

**Callers:**

| Symbol | VA |
|---|---|
| `ClientSpecialEvent_TeleportIn_ctor` | `0x00978d20` |
| `ClientSpecialEvent_TeleportOut_ctor` | `0x009781d0` |
| `FUN_00979310` | `0x00979310` |

---

## 6. Gaps

1. Product names: 0x78 slot type, controller at `+0x24`, flag `+0x4c`.
2. Why duration is global clock-derived vs resource-derived.
3. Fail-after-store: slot pointer may remain non-null on load fail (raw CF — intentional?).
4. Duals of path/resource helpers (not OWN).
5. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — ABI + CF + call-site this sealed; product English + fail residual open.
