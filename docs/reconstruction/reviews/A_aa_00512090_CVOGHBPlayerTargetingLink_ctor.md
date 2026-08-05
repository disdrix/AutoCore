# Review A (reconstruction fidelity): `aa_00512090` CVOGHBPlayerTargetingLink_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512090` |
| **VA** | `0x00512090`–`0x005120a8` (body inclusive; exclusive end `0x005120a9`; `int3` pad after) |
| **Canonical name** | `CVOGHBPlayerTargetingLink_ctor` (inferred class name; Ghidra `FUN_00512090`) |
| **Prior / alias** | `FUN_00512090`; `Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_00512090` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra decompile + `read_memory`) |
| **Reviewer role** | Independent reconstruction fidelity (targeting link HB self) |
| **Counterpart** | `reviews/B_aa_00512090_CVOGHBPlayerTargetingLink_ctor.md` |
| **System** | object / combat-target / HB |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Self-side targeting heartbeat constructor** used when an entity selects a non-self target.

1. Run the shared **base targeting HB ctor** `FUN_00604d40(attachOwner)` on `this` (same leaf the target-side HB uses directly).
2. **Overwrite** `*(void**)this` with subclass vtbl **`PTR_FUN_009cdfd4`** (`0x009cdfd4`) — the `CVOGHBPlayerTargetingLink` family.
3. Return `this`.

Object size at sole call site is **`0x28`**. Purge predicate `FUN_005121d0` RTTI-casts to **`CVOGHBPlayerTargetingLink`**, which is why only the self-side HB (this subclass) is destroyed when target changes — not the base-vtbl target-side HB.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00512090_FUN_00512090.md` | Append live stamp (body frozen) |
| Annotated | `docs/reconstruction/raw/aa_00512090_FUN_00512090.annotated.md` | Refined machine notes |
| Clean (named) | `docs/reconstruction/reconstructed-exact/CVOGHBPlayerTargetingLink_ctor.cpp` | New |
| Clean (alias) | `docs/reconstruction/reconstructed-exact/FUN_00512090.cpp` | Refined |
| Function record | `docs/reconstruction/functions/aa_00512090_CVOGHBPlayerTargetingLink_ctor.md` | New |
| Prior scaffold record | `docs/reconstruction/functions/aa_00512090_FUN_00512090.md` | Points at named dual |
| Live decompile | Ghidra `decompile_function` @ `0x00512090` | ≡ scaffold body |
| Live bytes | `read_memory` 80 B @ `0x00512090` | Full leaf + pad |
| Live xrefs / callers | `analyze_function_complete` / `get_function_callers` | **1** call site |
| Vtbl contrast | `read_memory` @ `0x009cdfd4` vs `0x009cdfb0` | Slot 0 / slot 7 differ |
| Parent dual | `reviews/A_aa_005172d0_Object_SetSelectedTarget.md` | Call site context only |

**Not performed:** Launcher, runtime golden, bit-exact package, dual of base `0x00604d40` / partner link `0x00604db0` / purge `0x005121d0` (OWN-ONLY this VA).

---

## 3. Signature (image-sealed)

```c
// __thiscall  ECX = this (fresh 0x28 allocation)
// stack: void *attachOwner   // entity that owns this self-side link
// ret 4
// returns this*
void *CVOGHBPlayerTargetingLink_ctor(void *this, void *attachOwner);
```

| Item | Evidence | Conf |
|---|---|---|
| `__thiscall` ECX = `this` | `mov esi,ecx`; store vtbl via `[esi]` | **High** |
| One stack arg (attach owner) | `mov eax,[esp+4]` / `push eax` / `ret 4` | **High** |
| Calls `FUN_00604d40(attachOwner)` with **same** `this` in ECX | ECX preserved across push; relative call target `0x00604d40` | **High** |
| Post-base: `*this = 0x009cdfd4` | `c7 06 d4 df 9c 00` | **High** |
| Returns `this` in EAX | `mov eax,esi` | **High** |
| Body end `ret 4` | `c2 04 00` at `0x005120a6` | **High** |
| Sole caller `Object_SetSelectedTarget` @ `0x00517374` | xrefs + callers | **High** |
| Alloc size `0x28` (caller) | parent dual / call-site `push 0x28` | **High** (caller-sealed) |
| Product class name `CVOGHBPlayerTargetingLink` | RTTI on purge sibling `0x005121d0` | **High** (class) / ctor symbol **Inferred** |
| Base leaves vtbl `0x009cdfb0`; this overrides | parent B + live vtbl dumps | **High** |

---

## 4. Byte seal (`read_memory` @ `0x00512090`)

```
00512090  8B 44 24 04           mov eax, [esp+0x4]     ; attachOwner
00512094  56                    push esi
00512095  50                    push eax               ; stack arg for base
00512096  8B F1                 mov esi, ecx           ; this
00512098  E8 A3 2C 0F 00        call 0x00604d40        ; next=0051209d; +0xF2CA3
0051209d  C7 06 D4 DF 9C 00     mov dword ptr [esi], 0x009CDFD4
005120a3  8B C6                 mov eax, esi
005120a5  5E                    pop esi
005120a6  C2 04 00              ret 4
005120a9  CC…                   int3 pad (not body)
```

**Relative call check:** `0x0051209d + 0x000F2CA3 = 0x00604D40` — sealed.

**Hex body:** `8b44240456508bf1e8a32c0f00c706d4df9c008bc65ec20400`

---

## 5. Control flow: clean ≡ raw ≡ live decompile ≡ bytes

| Stage | Match |
|---|---|
| Base ctor then vtbl write then return this | **Yes** |
| No extra fields written in this leaf | **Yes** |
| No null checks / no logging | **Yes** |
| `ret 4` one stack arg | **Yes** |
| Classification `wrapper` (analyze_function_complete) | **Yes** |

### Live decompile (2026-07-29)

```c
undefined4 * __thiscall FUN_00512090(undefined4 *param_1, undefined4 param_2)
{
  FUN_00604d40(param_2);
  *param_1 = &PTR_FUN_009cdfd4;
  return param_1;
}
```

≡ frozen 2026-07-23 scaffold raw body.

---

## 6. Algorithm (authoritative)

```
// __thiscall CVOGHBPlayerTargetingLink_ctor(this, attachOwner)
// this: freshly operator_new(0x28)'d HB object (caller responsibility)
FUN_00604d40(this, attachOwner);   // base targeting HB: vtbl 009cdfb0, attach, flags/period, Start
*this = vtbl_009cdfd4;             // promote to CVOGHBPlayerTargetingLink
return this;
```

**Vtbl contrast (OWN-ONLY surface — slot addresses only):**

| Slot | Base `0x009cdfb0` | Derived `0x009cdfd4` |
|---|---|---|
| 0 | `0x00512070` | **`0x0051b870`** |
| 1 | `0x00508270` | `0x00508270` |
| 2 | `0x005082c0` | `0x005082c0` |
| 3 | `0x00604dd0` | `0x00604dd0` |
| 4 | `0x005081e0` | `0x005081e0` |
| 5 | `0x00604ca0` | `0x00604ca0` |
| 6 | `0x00604ce0` | `0x00604ce0` |
| 7 | `0x0056f570` | **`0x0051b850`** |

Only **slot 0** and **slot 7** differ in the first eight entries — subclass overrides those two virtuals after sharing the base body init path.

---

## 7. Call surface (xrefs to this VA only)

| Caller | Site | Use |
|---|---|---|
| `Object_SetSelectedTarget` (`0x005172d0`) | `0x00517374` | Self-side of dual HB pair after `new(0x28)`; `attachOwner = entity` (selector), not the new target |

No other xrefs (`xref_count: 1`).

---

## 8. Gaps / open

1. Product C++ mangled ctor name (no string on this leaf); class name **High** via RTTI elsewhere.
2. Exact semantics of base `FUN_00604d40` fields/period/flags — **callee-owned**, not dualed here.
3. What derived vtbl slots `0x0051b870` / `0x0051b850` implement (tick / destroy / partner) — **other VAs**.
4. Whether any other binary/module constructs this class without going through `Object_SetSelectedTarget` (this image: no).

---

## 9. Verdict

**accept-with-gaps** — leaf is a sealed two-step subclass ctor (base + vtbl swap). Gaps are naming polish and out-of-VA virtual method bodies, not control-flow ambiguity.
