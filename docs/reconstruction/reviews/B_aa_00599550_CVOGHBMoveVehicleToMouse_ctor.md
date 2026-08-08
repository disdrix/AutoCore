# Review B (skeptical / adversarial): `aa_00599550` CVOGHBMoveVehicleToMouse_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00599550` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY **R13-007**) |
| **Counterpart** | `reviews/A_aa_00599550_CVOGHBMoveVehicleToMouse_ctor.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + xrefs/callers/callees. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is the scalar-deleting dtor | **Falsified** — no flags test, no `operator_delete`; dtor is parent dual `005996a0` |
| 2 | This is complete/body `00599570` | **Falsified** — body ends at `0059956f`; `00599570` restores vtbl then chains `00636b90` |
| 3 | Same unit as base MoveVehicle ctor `00636bd0` | **Falsified** — this unit **calls** base then overrides vtbl to `009d5590` (base installs `009e3b70`) |
| 4 | cdecl / stack `this` / RET 0 / RET 4 | **Falsified** — `MOV ESI,ECX`; `C2 08 00` (RET 8) |
| 5 | Zero code callers / DATA-only | **Falsified** — 4 UNCONDITIONAL_CALL factories |
| 6 | Product name unsealed / needs `_Inferred` | **Falsified** — RTTI `.?AVCVOGHBMoveVehicleToMouse@@` @ `0x00af33e0` |
| 7 | Does not call base / inlines base body | **Falsified** — single `CALL 00636bd0` |
| 8 | Writes entity at `+0x40` (not host ctx) | **Falsified** — entity is stack arg0 → base; arg1 → `+0x40`; callers pass `client+0xe04` as arg1 |
| 9 | Size is base-only / not 0x44 | **Falsified** — all callers `operator_new(0x44)` |
| 10 | This is OnEnd / OnHeartBeat / mouse aim math | **Falsified** — no steer/mouse math; pure construct shell |
| 11 | Installs MoveVehicle vtbl and leaves it | **Falsified** — base installs `009e3b70`, this overrides to `009d5590` |
| 12 | Runtime Confirmed | **Fails** — open (no Launcher); never claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this / RET 8 / return this | **High** | Wrong ABI port |
| Base ctor first then vtbl override | **High** | Incomplete construct |
| `+0x40` = stack arg1 only | **High** | Wrong field bind |
| RTTI CVOGHBMoveVehicleToMouse | **High** | Naming only if wrong |
| Size 0x44 | **High** | Wrong alloc |
| `+0x40` product type English | Open | Host-ctx type name |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
mov eax, [esp+4]           ; pEntity
push esi
push eax
mov esi, ecx               ; this
call FUN_00636bd0          ; CVOGHBMoveVehicle_ctor
mov ecx, [esp+0xC]         ; pHostCtx
mov dword [esi], 009d5590  ; ToMouse vtbl
mov [esi+0x40], ecx
mov eax, esi
pop esi
ret 8
```

Hex (32 B): `8b44240456508bf1e873d609008b4c240cc70690559d00894e408bc65ec20800`

Vtbl dword0 @ `0x009d5590` = `0x005996a0` (scalar dtor — parent dual). RTTI name `.?AVCVOGHBMoveVehicleToMouse@@`.

Reject ports that:

- Treat this as scalar dtor / complete body / base ctor body.
- Use RET 4 (one stack arg) — base is RET 4; **this is RET 8**.
- Skip base `00636bd0` or leave MoveVehicle vtbl installed.
- Bind entity into `+0x40` instead of host/world ctx.
- Claim runtime Confirmed without CE/Launcher.
- Force `_Inferred` despite RTTI-sealed product class.
- Merge with OnEnd `00636ba0` / OnHB `00636cc0` / base ctor `00636bd0`.

---

## 4. Surviving contract for AutoCore

```csharp
// CVOGHBMoveVehicleToMouse* Ctor(this, void* pEntity, void* pHostCtx)
// thiscall, ret 8
// CVOGHBMoveVehicle_ctor(this, pEntity);
// *this = &PTR_FUN_009d5590;
// *(this+0x40) = pHostCtx;
// return this;
// sizeof = 0x44
```

Port as MSVC thiscall subclass ctor for **CVOGHBMoveVehicleToMouse**. Pair base ctor `00636bd0` (dualed) and scalar dtor `005996a0` (parent dual). Keep distinct from:

- `CVOGHBMoveVehicle_ctor` `00636bd0` (base; RET 4; vtbl `009e3b70`)
- `CVOGHBMoveVehicleToMouse_ScalarDeletingDtor` `005996a0` (parent)
- Complete/body `00599570` (residual)
- Shared OnEnd `00636ba0` / OnHeartBeat `00636cc0`

---

## 5. Verdict

**accept-with-gaps** — adversarial checks confirm subclass constructor with RTTI-sealed product name, base chain, ToMouse vtbl override, and `+0x40` host-ctx store. Residual: `+0x40` product type English, complete body dual, runtime. Not reject. **Never Runtime Confirmed.**
