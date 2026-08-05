# Review A (reconstruction fidelity): `aa_0055fe50` Phys_RegisterAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055fe50` |
| **VA** | `0x0055fe50` |
| **Canonical name** | `Phys_RegisterAction` (inferred) |
| **Ghidra symbol** | `FUN_0055fe50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_0055fe50_Phys_RegisterAction.md` |
| **System** | `physics` (action / island registration) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Register a **sim action** into the world/island pipeline so later island steps can dispatch `applyAction` (e.g. `VehicleAction` vtbl `+0x14` @ `0x00598650`).

Authoritative behavior (thiscall **ECX = world/sim**, stack **action\***):

1. Bump action **ref halfword** at **`action+0x6`** (`add word ptr [action+6], 1`).
2. Build collect descriptor on stack (`local` count/cap with seed `capRaw = 0x80000004` style).
3. **`action->vtbl[+0x18](&collectBuf)`** — collect related body/hosts.
4. Store **`action+0x0c = world`** (back-link).
5. Iterate collected hosts:
   - Skip if host index `host+0x24 == -1`.
   - First valid: `FUN_006292a0(action)` (add to world/island action list — see `0.1-step-rate.md`), remember host; if `host+0x29==0` → `FUN_0055eb80` ActivateHost.
   - Later hosts with **different** `host+0x44` island key → `FUN_0055efd0` (cross-island link).
6. **`FUN_0062a3d0(world, action)`** post-register.
7. Free collect buffer if owned (`capRaw >= 0` path via allocator `+0x14`, tag `0x12`).
8. Return `action`.

Documented callers: `Vehicle_createVehicleAction` (`0x004fb660`), flipper ctor (`0x005075f0`), plus `FUN_005625c0`, `FUN_00642740`.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_0055fe50_FUN_0055fe50.md` | ≡ live (decompiler `unaff_EBX` = collect ptr) |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0055fe50.cpp` | CF ≡ raw |
| Live decompile | Ghidra MCP `0x0055fe50` | **≡ raw** |
| Live `read_memory` | entry | refcount `+6`, vtbl `+0x18` sealed |
| Prior verified | `fn_004fb660_createVehicleAction.md` § Registration | Role sealed |
| ActivateHost dual | `A_aa_0055eb80` | Ready path |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall` ECX=world, stack=action*; returns action | **High** | Asm `mov ebp,ecx`; `mov edi,[esp+…]` action |
| Refcount `*(u16*)(action+6)++` | **High** | `66 83 47 06 01` |
| Collect via action vtbl **`+0x18`** | **High** | `call [edx+0x18]` |
| `action+0xc = world` | **High** | `mov [edi+0xc], ebp` |
| First valid host → `FUN_006292a0(action)` | **High** | Prior art + decompile |
| Not-ready host → `PhysSim_ActivateHost` | **High** | `FUN_0055eb80` |
| Different `+0x44` → `FUN_0055efd0` | **High** | Decompile |
| Tail `FUN_0062a3d0(world, action)` | **High** | |
| Skip `host+0x24 == -1` | **High** | Inactive / free-list sentinel |
| Decompiler `unaff_EBX` is collect data ptr from vcall out-params | **High** | Stack collect pattern; not true undef reg |
| Product name | **Probable** | RegisterAction |
| Null action safety | **Low** | createVehicleAction notes null `*holder` still calls — crash surface |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Refcount++ | Yes |
| Collect vcall `+0x18` | Yes |
| Back-link world | Yes |
| Loop hosts; island add / activate / cross-link | Yes |
| `FUN_0062a3d0` | Yes |
| Conditional free collect buffer | Yes |
| Return action | Yes |

---

## 5. Callers / callees

**Callees:** action vtbl `+0x18`, `FUN_006292a0`, `FUN_0055eb80`, `FUN_0055efd0`, `FUN_0062a3d0`, allocator free `DAT_00b05060+0x14`.

**Callers:** `Vehicle_createVehicleAction`, `FUN_005075f0` (flipper), `FUN_005625c0`, `FUN_00642740`.

---

## 6. Gaps / open

1. Full duals for `FUN_006292a0`, `FUN_0055efd0`, `FUN_0062a3d0`.
2. Collect buffer exact layout beyond count/cap/data.
3. Guaranteed non-null action policy (retail can pass null).
4. Runtime not run.

**Verdict:** **accept-with-gaps** — refcount, collect slot, back-link, activate-on-demand, and island add path sealed; sub-callees residual.
