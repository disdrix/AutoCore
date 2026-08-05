# Review A (reconstruction fidelity): `aa_0053d970` Object_SetPhysBodyTypeIfNotReady_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053d970` |
| **VA** | `0x0053d970` |
| **Canonical name** | `Object_SetPhysBodyTypeIfNotReady_Inferred` |
| **Ghidra symbol** | `FUN_0053d970` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ **machine** CF; decompiler incomplete) |
| **Counterpart** | `reviews/B_aa_0053d970_Object_SetPhysBodyTypeIfNotReady_Inferred.md` |
| **System** | physics / entity shell (type-6 soft path; multi-class object) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** — CF + ABI + type-map sealed from **machine**; product type enum English open |

---

## 1. Purpose

Gated **physics body-type request** for a CVOG object (vehicle / creature / spawn-owned entity):

1. Load **`phys = entity+0x08`**. If null → **no-op** (`RET 4`).
2. Compute **not-fully-ready** = `(phys+0x40 == 0) || (phys+0x08 == 0)` — same soft-shell readiness used by network pose apply (`FUN_0053eec0`).
3. If **fully ready** → **no-op** (`RET 4`); do **not** call the mode switcher.
4. If not ready → **tail-call** `FUN_005d4440(phys, targetType)` with:
   - **`ECX = phys`** (not the entity)
   - **`targetType = (stackFlag == 0) ? 1 : 6`**

Role in vehicle ghost path (`Vehicle_setDrivingInputs`): caller only invokes when body-type vfunc returns **6**, and passes **flag 0** → this unit forces switch toward **type 1** while the shell is still soft/not-ready (“leave type-6” cleanup). Other callers pass **flag 1** to request **type 6**.

**Not** a full body-type switcher (that is `FUN_005d4440`); this is the **entity-level soft gate + 1/6 map + tail**.

---

## 2. Inspected artifacts

| Artifact | Path / tool | This pass |
|---|---|---|
| Live decompile | Ghidra `decompile_function` / `force_decompile` @ `0x0053d970` | Incomplete (drops stack arg + type rewrite) |
| Live bytes | `read_memory` len 80 @ entry | **Authoritative** full CF |
| Callee | `decompile_function` @ `0x005d4440` | Body-type switcher; thiscall `(phys, type)` |
| Call sites | `get_assembly_context` on 22 xrefs | Push 0 / 1 + `mov ecx, entity` before call |
| Callers list | `analyze_function_complete` | 20 named callers / 22 xrefs |
| Prior dual context | `A/B_aa_00504c70_Vehicle_setDrivingInputs` | Type-6 gate + ECX=entity sealed |
| Soft-ready twin | `physics/verified/fn_0053eec0_networkApply.md` | Same `+0x40` / `+0x08` readiness |
| Raw / annotated / clean | `raw/aa_0053d970_*`, `reconstructed-exact/FUN_0053d970.cpp` | Re-verify append + rewrite |

**Not performed:** Launcher, runtime, bit-exact, full product enum catalog for types 1/6/7, dual of `FUN_005d4440` (leave-FUN).

**Avoided:** `disassemble_bytes` (project rule). CF recovered via `read_memory` + call-site assembly context.

---

## 3. Authoritative body (machine, 2026-07-29)

Body range **`0x0053d970`–`0x0053d9ac`** (`RET 4` at `0x0053d9aa`; `INT3` pad after).

```text
; ECX = entity*, [esp+4] = flag (u32; callers push 0 or 1)

mov  ecx, [ecx+8]          ; phys = entity+0x08
test ecx, ecx
jz   .ret4                 ; null phys → no-op

mov  al, [ecx+0x40]        ; ready / mode-7 sticky byte (see 5d4440 store)
test al, al
jz   .not_ready
cmp  dword [ecx+8], 0      ; phys+0x08 secondary readiness
jz   .not_ready
xor  al, al                ; fully ready
jmp  .test
.not_ready:
mov  al, 1
.test:
test al, al
jz   .ret4                 ; fully ready → no-op

cmp  byte [esp+4], 0
mov  dword [esp+4], 6      ; default rewrite → type 6
jnz  .tail                 ; flag != 0 → keep 6
mov  dword [esp+4], 1      ; flag == 0 → type 1
.tail:
jmp  FUN_005d4440          ; tail; ECX=phys; [esp+4]=targetType
.ret4:
ret  4
```

Hex prefix (entry, 61 bytes to `RET 4`):

```
8B 49 08 85 C9 74 33 8A 41 40 84 C0 74 0A 83 79 08 00 74 04
32 C0 EB 02 B0 01 84 C0 74 1C 80 7C 24 04 00 C7 44 24 04 06
00 00 00 75 08 C7 44 24 04 01 00 00 00 E9 96 6A 09 00 C2 04 00
```

Rel32 of tail `JMP`: `0x0053d9AA + 0x00096A96 = 0x005D4440` — sealed.

---

## 4. ABI

| Item | Value | Confidence |
|---|---|---|
| Convention | MSVC **`__thiscall`** (ECX = entity; one stack arg; **`RET 4`**) | **High** |
| `this` | Object / entity base (vehicle, creature, …) | **High** (callers) |
| Stack arg | Integer flag: **0 → target type 1**, **≠0 → target type 6** | **High** (machine) |
| Return | void (no EAX contract observed) | **High** |
| Callee this | **`phys`** after `mov ecx,[entity+8]` | **High** |
| Callee stack | Target body type **1** or **6** (rewritten over flag slot) | **High** |
| Tail call | **`JMP FUN_005d4440`** (not `CALL`+`RET`) | **High** |

Decompiler display `void __fastcall FUN_0053d970(int param_1)` with bare `FUN_005d4440()` is **wrong / incomplete** for ports.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Gate `entity+0x08 != 0` | **High** | `test ecx,ecx; jz ret4` after load |
| Ready: `phys+0x40` byte | **High** | `mov al,[ecx+0x40]; test al` |
| Ready also requires `phys+0x08 != 0` | **High** | `cmp [ecx+8],0` |
| Same readiness as soft network path | **High** | Matches `fn_0053eec0` `notFullyReady` |
| Fully ready → pure no-op | **High** | Skip type rewrite + jmp |
| Flag 0 → type **1** | **High** | Overwrite 6 then 1 when ZF |
| Flag ≠0 → type **6** | **High** | Keep 6 after `jnz` |
| Tail to `0x005d4440` with phys this | **High** | rel32 + ECX |
| Callers pass entity in ECX | **High** | e.g. `mov ecx,esi; push 0; call` at setDrivingInputs |
| Vehicle ghost uses flag **0** after type==6 probe | **High** | `A_aa_00504c70` + live site `0x00504c91` |
| Product English for type 1 / 6 / 7 | **Low–Probable** | 5d4440 treats 6/7 specially; no string here |
| Function product/PDB name | **Open** | `_Inferred` suffix |
| Runtime / bit-exact | **Open** | Static only |

---

## 6. Call graph (static, this pass)

**Callee (1):** `FUN_005d4440` @ `0x005d4440` — body/AI mode switcher.

**Callers (sample sealed by assembly context):**

| Site | Caller (Ghidra) | Flag push | Notes |
|---|---|---|---|
| `0x00504c91` | `Vehicle_setDrivingInputs` | **0** | Only if type vfunc == 6 |
| `0x005057dd` | `FUN_005057c0` | **0** | Same type-6 pattern |
| `0x005040e4` | `Vehicle_ActivateEnterWorld` | **0** | |
| `0x004feee6` | `FUN_004fedc0` | **1** | |
| `0x004ff23b` | `FUN_004fedc0` | **0** | |
| `0x004c5ca6` | `CVOGCreature_PostCreateFromPacket` | **1** | |
| `0x00564691` | `CVOGSpawnPoint_CreateTemplateVehicle` | **1** | |
| `0x00564853` / `0x005648c1` | `CVOGSpawnPoint_SetObjectActiveState` | reg / reg | Active-state path |
| `0x00979603` | `FUN_00979310` (respawn airlift) | **1** | |
| `0x0091a88b` | `FUN_0091a5f0` (camera look offset) | **0** | |

Full xref count: **22** (`analyze_function_complete`).

---

## 7. Control flow: machine ≡ intended clean

| Stage | Match |
|---|---|
| Null phys early out | **Yes** |
| Dual readiness (`+0x40` / `+0x08`) | **Yes** |
| Fully-ready no-op | **Yes** |
| Flag→{1,6} rewrite | **Yes** (machine; **not** in old scaffold decompile) |
| Tail `FUN_005d4440` | **Yes** |
| `RET 4` | **Yes** |
| No invent of type-7 path here | **Yes** (7 only inside leave-FUN) |

---

## 8. Gaps

1. Product names for body types **1** and **6** (and sibling **7** in `FUN_005d4440`).
2. Full dual A/B of `FUN_005d4440` (leave-FUN; large).
3. Whether `phys+0x40` is exclusively “type==7 sticky” (5d4440 writes `param_2==7`) vs broader ready flag — **CF sealed**, English open.
4. Runtime confirmation that type-6 ghost leave-path always hits soft (not-ready) shells.
5. Bit-exact / differential package.

---

## 9. AutoCore impact (fidelity)

- Port as **entity thiscall + flag**, not as `void f(entity)` or `FUN_005d4440()` with no type.
- **Never** pass null this: decompiler `(0)` at call sites is the **flag**, not the object.
- When flag is 0, request type **1**; when flag is 1, request type **6** — do not invert.
- Only mutates via `FUN_005d4440` when the phys shell is **not fully ready**; hard-ready shells are intentionally left alone.
- Vehicle network type-6 gate + flag 0 = soft leave toward type 1 before thr/steer/pose apply.
