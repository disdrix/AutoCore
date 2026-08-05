# Function record: FUN_0052dac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052dac0` |
| **Canonical name** | `FUN_0052dac0` |
| **Product name** | Reward-region lookup/insert helper (Tentative) |
| **Address** | `0x0052dac0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Completion status** | **Sealed (CF + ABI)** — dual A/B + three-rep decompile agree; assembly confirms |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `Named_CalleeOf_Client_ShowNpcMissionDialogUI_0052dac0`
- Wave label: **Reward region helper**

## Purpose

`__thiscall` map lookup on container field `this+0x508` (red-black / tree map; end sentinel at `this+0x50c`), keyed by stack arg0.

- **Hit:** return `node + 0x18` (value / “reward region” blob).
- **Miss + create flag == 0:** return `NULL` (`xor eax,eax`).
- **Miss + create flag != 0:** zero-fill-ish payload (11× `0xFFFFFFFF` dwords + trailing byte `0` into a 12-dword copy window), call `FUN_0052c700(key, payload*)` to insert/update, return that call’s `EAX` = `node + 0x18`.

Does **not** interpret reward contents; only returns the region pointer (or null / newly inserted region).

## Signature (assembly-sealed)

```c
/* __thiscall  |  ret 8  |  ECX = container */
void *FUN_0052dac0(void *this, /* stack */ uint32_t key, /* stack */ char createIfMissing);
```

| Slot | Role | Evidence |
|---|---|---|
| `ECX` / `this` | Container with map @ `+0x508`, sentinel @ `+0x50c` | `mov esi,ecx`; `lea ecx,[esi+0x508]`; `cmp eax,[esi+0x50c]` |
| Stack `+4` | Key (mission id / def id) | `lea eax,[esp+0x3c]` → `&param_2` into lookup; callers push mission/`*def` |
| Stack `+8` | `createIfMissing` (byte; 0 or 1) | `cmp byte [esp+0x40],0`; callers `push 0` or `push 1` |
| `EAX` return | `node+0x18` region*, or `0` | `add eax,0x18` hit path; `xor eax,eax` miss; create path uses `FUN_0052c700` which ends `add eax,0x18` |

Decompiler warning *“Type propagation algorithm not settling”* remains; it **mis-attributes** `FUN_00538a40`’s `this` as whole `param_1` instead of `param_1+0x508`. Prefer assembly for the map base.

## Control flow (three return sites)

```
lookup(map@this+0x508, key) → node
if node != sentinel@this+0x50c:
    return node + 0x18
if createIfMissing == 0:
    return 0
fill payload with 0xFFFFFFFF…; payload trailing byte = 0
return FUN_0052c700(this, key, &payload)   // EAX = node+0x18
```

## Callees

| VA | Name | Role |
|---|---|---|
| `0x00538a40` | `FUN_00538a40` | Tree lower_bound / find; `this` = map @ container+0x508; out node* |
| `0x0052c700` | `FUN_0052c700` | Insert-or-overwrite value (12 dwords @ node+0x18); stores key @ node+0x40; **returns node+0x18** (decompiler often shows `void` — wrong) |

## Callers (5 xrefs)

| Site | Function | `createIfMissing` | Notes |
|---|---|---|---|
| `0x00943a85` | `Client_ShowNpcMissionDialogUI` | **0** | `ECX = *(client+0xe98)` char; key = `*missionDef`; result → reward chrome (`FUN_008aa760`) |
| `0x004d0912` | `FUN_004d08c0` | **1** | create path; `mov ebp,eax` |
| `0x004d5d20` | `FUN_004d5c10` | **1** | writes `[eax+0x2c]` after return |
| `0x004d5e90` | `FUN_004d5c10` | **1** | writes `[eax+0x2c]` after return |
| `0x004d63f6` | `FUN_004d5c10` | **1** | create path |

## Node / region layout (partial, from this unit + callees)

| Offset | Field |
|---|---|
| node `+0x10` | key (compare field in `FUN_00538a40`) |
| node `+0x18` | **value / reward region** (return base) |
| node `+0x40` (= region `+0x28`) | key written by `FUN_0052c700` |
| region `+0x2c` | written by `FUN_004d5c10` callers (byte) |

Payload on create: 12 dwords copied into `node+0x18`; this unit sets dwords of `-1` for the bulk of that window and a trailing `0` byte before insert.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0052dac0_FUN_0052dac0.md`
- Annotated: `docs/reconstruction/raw/aa_0052dac0_FUN_0052dac0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0052dac0.cpp`

## Verification

| Method | Result |
|---|---|
| Decompile A (`decompile_function`) | CF as above |
| Decompile B (`force_decompile`) | **Identical** to A |
| Decompile C (`batch_decompile`) | **Identical** to A/B |
| `read_memory` full body (~0x90 bytes, ends `ret 8` ×3) | Seals `this+0x508` / `+0x50c`, `+0x18`, `ret 8`, three exits |
| Caller `read_memory` (5 sites) | Seals `push 0` vs `push 1` and use of `EAX` as region* |

## Confidence

| Claim | Level |
|---|---|
| Control flow (3 exits) | **High** (A≡B≡C + asm) |
| ABI: thiscall, 2 stack args, `ret 8` | **High** |
| Map @ `+0x508`, sentinel `+0x50c`, value @ node `+0x18` | **High** |
| Return = reward/value region* or null | **High** (CF); product name **Tentative** |
| Create path returns valid region* via `FUN_0052c700` | **High** (asm end of `0052c700`: `add eax,0x18`) |
| Exact 12-dword payload init (uninit upper bytes of last dword) | **Probable** — only low byte of last unit forced to 0 |
| Container type name (char vs mission mgr) | **Tentative** — same offsets; UI path uses `client+0xe98` |
| Runtime / bit-diff | **Open** |

## Gaps

1. Full reward-region struct field map beyond `+0x28` key / `+0x2c` byte.
2. Product name for container type and for `FUN_0052c700` / `FUN_00538a40`.
3. Whether miss+create’s last payload dword high bytes are intentionally don’t-care.
4. Runtime verification not run.
