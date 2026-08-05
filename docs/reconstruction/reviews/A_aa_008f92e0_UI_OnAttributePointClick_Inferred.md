# Review A (reconstruction fidelity): `aa_008f92e0` UI_OnAttributePointClick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008f92e0` |
| **VA** | `0x008f92e0` |
| **Body** | `0x008f92e0`–`0x008f96bc` (~`0x3DC` B incl. switch tables) |
| **Canonical name** | `UI_OnAttributePointClick_Inferred` |
| **Prior names** | (none in inventory beyond inferred) |
| **Review date** | `2026-07-29` (dual A/B — wave6 dual-w6-attrpt) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_008f92e0_UI_OnAttributePointClick_Inferred.md` |
| **System** | `missions-progression` / character sheet UI (client) |
| **Dual status** | **Present** (supersedes 2026-07-23 scaffold-only record) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Character-sheet / UI message handler** that spends one free point from the local character’s **pool short at `char+0x6ce`** into one of four **stat shorts** (`+0x13c` / `+0x13e` / `+0x140` / `+0x142`), then refreshes chrome and optionally emits **sector packet opcode `0x205A`** with a per-stat flag mask.

Product evidence: toast string  
`"You cannot apply attribute points while in an arena!"`  
(data `s_You_cannot_apply_attribute_point_00a35b48`).

**Not** a pure leaf: local optimistic mutation + gated network notify. Arena and empty-pool paths return success-consumed (`1`) without spend.

**Calling convention (body-sealed):** MSVC `__thiscall`

| Slot | Role | Evidence |
|------|------|----------|
| `this` (ECX → EDI) | UI widget / dialog host (`param_1`) | prologue `mov edi, ecx`; vtbl calls `*param_1+0x448`, `+0x34c` |
| stack0 | `int eventType` (`param_2`) | `mov eax,[esp+…]`; primary path requires `== 8` |
| stack1 | `uint controlId` (`param_3`) | `lea ecx,[edx-0x9c40]`; switch range 0..4 |
| EAX/AL | handled flag (`0` if no local player; else usually `1`) | early `xor al,al` / success `mov al,1`; `ret 8` |
| epilogue | `add esp,8; ret 8` | two stack args cleaned |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008f92e0_UI_OnAttributePointClick_Inferred.md` |
| Annotated | `docs/reconstruction/raw/aa_008f92e0_UI_OnAttributePointClick_Inferred.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_OnAttributePointClick_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_008f92e0_UI_OnAttributePointClick_Inferred.md` |
| Live decompile | Ghidra `decompile_function` / `analyze_function_complete` `0x008f92e0` (2026-07-29) ≡ raw body |
| Live bytes | `read_memory` entry `0x008f92e0` len 64; epilogue region `0x008f96a0` — `ret 8` |
| Xrefs | single **DATA** ptr at `0x00a35a2c` (vtable / handler table slot; value `0x008f92e0`) |
| Callees (named / body) | `CVOGCharacter_AddSkillPoints`, `Client_RefreshMissionDialogChrome`, `Client_SendSectorPacket`, `Vehicle_RecalcCombatPools`, `Vehicle_CalcHeatMaximum`, toast `FUN_007fdfb0`, default `FUN_0087b500`, getters/setters `0x0040dd*0` / `0x004c2e*` |
| Pool twin | dual A/B `aa_005312c0` `CVOGCharacter_AddSkillPoints` (`+0x6ce` assign) |
| Pool sibling | dual A/B `aa_00531250` `CVOGCharacter_AddAttributePoints` (`+0x6cc` — **not** used by this VA) |

**Not performed:** `disassemble_bytes`, Launcher, live process memory, bit-exact image diff, full product names of the four stats.

---

## 3. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| `DAT_00d1b6d8 == 0` → return `0` | **Yes** — prologue `mov esi,[DAT_00d1b6d8]; test esi,esi` |
| `switch (controlId - 0x9C40)` cases 0..4 else fall out | **Yes** — `lea ecx,[edx-0x9c40]; cmp ecx,4; ja; jmp [table]` |
| Primary branch only when `eventType == 8` | **Yes** — each case `cmp eax,8` / decomp `param_2 == 8` |
| Case `0x9C40` (40000): `FUN_007fca10(); return 1` | **Yes** |
| Cases `0x9C41`–`0x9C44`: pool `< 1` → return `1` (no spend) | **Yes** — `*(short*)(char+0x6ce)` |
| Arena gate: `DAT_00d1b644 != 0 && *(char*)(DAT_00d1b644+0xf6) != 0` → toast + return `1` | **Yes** — shared label / duplicated for last case |
| Get stat (clamp display ≤200) → set `value+1` | **Yes** — paired get/set VAs below |
| Assign free pool to `old-1` via `CVOGCharacter_AddSkillPoints` | **Yes** — assignment API, not `+=` |
| Refresh mission chrome + `this` vtbl `+0x448` then `+0x34c` | **Yes** |
| Optional online gate `FUN_00807440` → if false, return `1` **without** sector packet | **Yes** |
| Else build `{u32 opcode=0x205A, u32 flags}` and `Client_SendSectorPacket(&DAT_00d1a840, 8, &pkt)` | **Yes** |
| Fallthrough `switch(eventType)`: 7,8,0xD,0xE → `1`; else `FUN_0087b500(event, control)` | **Yes** |
| `ret 8` | **Yes** |

### 3.1 Control ID → stat offset → packet flag — **SEALED**

| `controlId` | Get VA | Set VA | Char short | Packet `flags` | Extra side effects |
|-------------|--------|--------|------------|----------------|--------------------|
| `0x9C41` (40001) | `FUN_0040de30` | `FUN_004c2ef0` | **`+0x13E`** | `0x00000001` | none beyond common refresh |
| `0x9C42` (40002) | `FUN_0040de10` | `FUN_004c2ee0` | **`+0x13C`** | `0x00010000` | if vehicle `char[0x94]` (`+0x250`): `Vehicle_RecalcCombatPools`; `nMaxHeat = Vehicle_CalcHeatMaximum`; optional `DAT_00d1b8b8` vtbl `+0x3d8` → `FUN_008801b0` |
| `0x9C43` (40003) | `FUN_0040ddf0` | `FUN_004c2f00` | **`+0x140`** | `0x00000100` | `(*char->vtbl)[+0x5c]()`; same optional `DAT_00d1b8b8` refresh |
| `0x9C44` (40004) | `FUN_0040ddd0` | `FUN_004c2f10` | **`+0x142`** | `0x01000000` | none beyond common refresh |
| `0x9C40` (40000) | — | — | — | — | `FUN_007fca10` only (no pool/stat change) |

Getters (`__fastcall`): load short at offset; if `> 199` return **200** (soft display/effective ceiling for the increment source).  
Setters (`__thiscall`): store `uint16` at same offset — **no** clamp on write.  
Implication: if true stored value already `> 200`, get returns 200 and set writes **201**.

### 3.2 Free-point pool — **SEALED (offset + API); product label open**

- Gate and spend use **`*(int16*)(localChar + 0x6CE)`**.
- Spend calls `CVOGCharacter_AddSkillPoints(pool - 1)` which **assigns** `+0x6ce = param` (see dual `aa_005312c0`), dirties `char+0x634 |= 0x40`, may LogicUI toast type `0x21` if new value increases the pool.
- Product string for the arena block says **“attribute points”**.
- Separate dual `aa_00531250` owns **`+0x6CC`** via `CVOGCharacter_AddAttributePoints` — **not referenced** by this function body.

**Naming honesty:** RE name `AddSkillPoints` is the existing sealed API for `+0x6ce`; this UI’s user-facing string says attribute points. Do not conflate with `+0x6cc` without further product proof.

### 3.3 Decompiler noise — **SEALED as artifact**

- Getters/setters appear as `FUN_0040de30()` / `FUN_004c2ef0(i+1)` with elided `ECX = localChar`. Callee signatures require character `this` / fastcall arg at the stat offsets — sealed by callee bodies, not by phantom args in this decomp.
- `FUN_00807440` decomp uses `in_EAX` as object base (`+0xc78` online/session probe) — treat as **connection / session gate before send**, not as a pure global.
- `analyze_function_complete` signature display `undefined …(void)` is **wrong**; locals + `ret 8` seal two stack params + thiscall.

---

## 4. Offsets & immediates (body-backed)

| Site | Width | Role |
|------|-------|------|
| `DAT_00d1b6d8` | ptr | local player / character* |
| char `+0x6CE` | i16 | free spendable points pool |
| char `+0x13C` | i16 | stat for control `0x9C42` |
| char `+0x13E` | i16 | stat for control `0x9C41` |
| char `+0x140` | i16 | stat for control `0x9C43` |
| char `+0x142` | i16 | stat for control `0x9C44` |
| char `+0x250` (`[0x94]`) | ptr | vehicle* (combat pool / heat path) |
| char vtbl `+0x5C` | method | post-stat refresh (case `0x9C43` only) |
| `DAT_00d1b644 + 0xF6` | u8 | arena lockout flag (nonzero → block spend) |
| `DAT_00d1a840` | client ctx | toast + `Client_SendSectorPacket` first arg |
| `DAT_00d1b8b8` | UI* | optional secondary UI refresh (`vtbl+0x3d8`, `FUN_008801b0`) |
| UI `this` vtbl `+0x448`, `+0x34C` | methods | dialog / sheet refresh after spend |
| Packet opcode | u32 | **`0x205A`** |
| Packet size | | **8** bytes (`opcode` + `flags`) |
| Event type | | **`8`** = apply click for control cases |
| Soft stat cap on get | | **200** |

---

## 5. Call graph / wiring

| Direction | Detail |
|-----------|--------|
| **Xref** | 1× DATA `0x00a35a2c` → function ptr (handler table / vtable slot; siblings at following dwords) |
| **Callers (code)** | none via UNCONDITIONAL_CALL — **dispatch is data-driven** |
| **Spend API** | `CVOGCharacter_AddSkillPoints` (`0x005312c0`) |
| **Net** | `Client_SendSectorPacket` with opcode `0x205A` (sibling skill-train uses `0x2059` / `0x2062` elsewhere) |
| **Vehicle** | `Vehicle_RecalcCombatPools`, `Vehicle_CalcHeatMaximum` only on control `0x9C42` |
| **Default** | `FUN_0087b500` for non-handled event types outside {7,8,0xD,0xE} |

---

## 6. Naming

| Claim | Confidence |
|---|---|
| Role = UI click handler spending free points into four char stats | **High / Sealed** |
| Canonical `UI_OnAttributePointClick_Inferred` | **Probable** (string-backed “attribute points”; PDB unknown) |
| Control IDs `0x9C40`–`0x9C44` are sheet widget IDs | **High** (switch math) |
| Event `8` = primary “click / apply” message | **High** (gate on all spend paths) |
| Product names of the four stats (Combat/Power/…) | **Open** |
| Whether free pool `+0x6ce` is product “skill points” or “attribute points” | **Open** (API name vs toast string conflict) |

---

## 7. Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / size | **High** (`008f92e0`–`008f96bc`) |
| Signature (`__thiscall` + 2 stack args, `ret 8`) | **High** |
| Control flow / switch IDs | **High** (live ≡ raw 2026-07-29) |
| Stat offset map + flags | **High / Sealed** |
| Pool `+0x6ce` spend via AddSkillPoints assign | **High** |
| Arena string + gate | **High** |
| Packet `0x205A` / 8-byte layout | **High** |
| Handler table install site / which dialog class | **Open** (data xref only) |
| Product stat names | **Open** |
| Server authority / echo of optimistic client write | **Open** |
| Runtime / bit-exact | **Open** |
| Overall | **accept-with-gaps** |

---

## 8. Contract for AutoCore (client mirror)

```
// eventType==8, controlId in 0x9C41..0x9C44, localChar != null
if (localChar->freePoints_i16(+0x6CE) < 1) return Handled;
if (arenaCtx && arenaCtx->flag(+0xF6)) { Toast(arenaMsg); return Handled; }
cur = GetStatClamped200(localChar, offsetFor(controlId));
SetStat(localChar, offsetFor(controlId), cur + 1);
CVOGCharacter_AddSkillPoints(localChar, freePoints - 1);  // assigns +0x6CE
// case-specific vehicle / vtbl side effects
RefreshChrome(ui);
if (!SessionAllowsSectorSend(ui)) return Handled;
SendSector(0x205A, flagFor(controlId));  // 8-byte payload
return Handled;
```

Gaps that remain intentionally open: product labels for the four stats; whether server re-validates the same offsets/flags; relationship of `+0x6cc` attribute pool to this spend path.
