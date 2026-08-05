# Review A (reconstruction fidelity): `aa_0058d980` CVOGPhysics_ApplyPointImpulse

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058d980` |
| **VA** | `0x0058d980` |
| **Canonical name** | `CVOGPhysics_ApplyPointImpulse` (inferred) |
| **Ghidra name** | `FUN_0058d980` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B, W16-B) |
| **Counterpart** | `reviews/B_aa_0058d980_CVOGPhysics_ApplyPointImpulse.md` |
| **System** | `physics` / `CVOGPhysics` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`CVOGPhysics` helper: optional readiness prepare, then forward **two** caller-supplied pointers to the bound rigid body via **body vtbl +0x60** — **apply point impulse** (impulse vector + point/contact object).

Same ready-gate prologue as one-arg siblings; differs by final vtbl slot and **arity 2** (`ret 8`):

| Unit | VA | Final call | Args | ret |
|---|---|---|---|---|
| `ApplyImpulseVector` | `0x0040d260` | `[EDX+0x50]` | 1 | 4 |
| `SetAngularVelocity` | `0x0040d040` | `[EDX+0x54]` | 1 | 4 |
| `ApplyVector_Vtbl5c` | `0x00404cb0` | `[EDX+0x5c]` | 1 | 4 |
| **this** | **`0x0058d980`** | **`[EDX+0x60]`** | **2** | **8** |

No clamps, no math, no field stores of its own. Prior art (`physics/0.4-suspension.md`) names chassis RB vtbl `+0x60` **applyPointImpulse** (hardpoint impulse at wheel contact).

---

## 2. Inspected artifacts

| Artifact | Path / tool | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_0058d980_FUN_0058d980.md` | ≡ live decompile; append seal |
| Annotated | `docs/reconstruction/raw/aa_0058d980_FUN_0058d980.annotated.md` | Refined |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGPhysics_ApplyPointImpulse.cpp` | CF ≡ raw |
| Ghidra twin | `reconstructed-exact/FUN_0058d980.cpp` | Same CF |
| Named scaffold alias | `Named_CalleeOf_…_Nam_0058d980.cpp` | Prior under-name |
| Function record | `functions/aa_0058d980_CVOGPhysics_ApplyPointImpulse.md` | Written |
| Live decompile | Ghidra MCP `decompile_function` @ `0x0058d980` | **≡ raw** |
| Live `read_memory` | 96 B @ `0x0058d980` | vtbl imm **`0x60`**, `ret 8` sealed |
| Ready helpers | decompile `0x005070b0`, `0x005070d0` | Probe / prepare sealed |
| Sibling duals | `A/B_aa_0040d040_*`, `A/B_aa_0040d260_*`, `A/B_aa_00404cb0_*` | Gate parity |
| Prior art | `physics/0.4-suspension.md` | applyPointImpulse @ +0x60 |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`, live xref dump (OWN-ONLY tool constraint: decompile + read_memory).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall` ECX=`phys`; two stack args; **`ret 8`** | **Confirmed** | `C2 08 00`; ESI=`this` |
| Optional ready: `FUN_005070b0` out-byte; if 0 **and** `phys+0x44≠0` → `FUN_005070d0` | **Confirmed** | decompile + instruction sequence |
| Ready probe: if `phys+0x44==0` → out=`0`; else out=`*(*(phys+0x44)+0x29)` | **High** | sealed sibling dual of `0x5070b0` |
| `body = *(phys+0x3c)` | **Confirmed** | `mov ecx,[esi+0x3c]` |
| Dispatch `(**body_vtbl)[+0x60](impulse, point)` | **Confirmed** | `call dword ptr [edx+0x60]` — imm sealed |
| Push order RTL: point then impulse → formals (impulse, point) | **Confirmed** | two `push` before call |
| Semantic: apply **point** impulse (not pure COM lin impulse) | **High** | prior art + two-arg shape vs +0x50 one-arg |
| Sibling parity of ready gate | **Confirmed** | byte-identical prologue family |
| No body-null check before vtbl | **Confirmed** | null → fault |
| Always prepares (`5070d0`) | **Falsified** | only when probe out==0 **and** `+0x44≠0` |
| Exact Havok / RTTI method name | **Open** | prior-art English only |
| `point` object layout (wheel vs float3) | **Open** | caller duals |
| Full caller inventory | **Open** | OWN-ONLY no xrefs tool |
| `phys+0x44` / `+0x29` English types | **Tentative** | behavior sealed |

---

## 4. Control flow: clean ≡ raw ≡ instructions

| Stage | Match |
|---|---|
| Save `this` in ESI | Yes |
| Out-byte on stack → `FUN_005070b0(this, &out)` | Yes (decompiler `uStack_4` artifact; asm `lea [esp+7]`) |
| If `*out==0` and `*(this+0x44)!=0` → `FUN_005070d0(this)` | Yes |
| `body=*(this+0x3c)`; push point; push impulse; `call [(*body)+0x60]` | Yes |
| `ret 8` thiscall | Yes |
| No invent lin-only / ang / pos / clamp | Yes |

### Recovered CF

```c
// void __thiscall CVOGPhysics_ApplyPointImpulse(phys, impulse, point)
out = ProbeReadyFlag(phys);           // FUN_005070b0
if (*out == 0 && *(phys+0x44) != 0)
  PrepareReady(phys);                 // FUN_005070d0
body = *(phys+0x3c);                  // NO null check
(*body->vtbl)[+0x60](impulse, point); // applyPointImpulse
```

### Instruction seal (`read_memory` 2026-07-29)

```text
51 56                  push ecx / push esi
8D 44 24 07 50         lea eax,[esp+7]; push eax
8B F1                  mov esi, ecx
E8 .. .. .. ..         call FUN_005070b0
80 38 00               cmp byte [eax], 0
75 0D                  jnz skip_prepare
83 7E 44 00            cmp dword [esi+0x44], 0
74 07                  jz skip_prepare
8B CE                  mov ecx, esi
E8 .. .. .. ..         call FUN_005070d0
8B 44 24 10            mov eax, [esp+0x10]   ; point
8B 4E 3C               mov ecx, [esi+0x3c]
8B 11                  mov edx, [ecx]
50                     push eax
8B 44 24 10            mov eax, [esp+0x10]   ; impulse
50                     push eax
FF 52 60               call dword [edx+0x60] ; *** 0x60 ***
5E 59 C2 08 00         pop esi; pop ecx; ret 8
```

Body size **0x37** bytes (to `ret 8` inclusive).

---

## 5. Callers / callees (inventory)

| Direction | Targets |
|---|---|
| **Callees** | `FUN_005070b0` @ `0x005070b0`, `FUN_005070d0` @ `0x005070d0`, indirect vtbl+0x60 |
| **Callers** | Open under OWN-ONLY (no xref tool). Scaffold seed: nested VOG_DEBUG callee chain |
| **Inline peer** | postTick / suspension also call body `+0x60` **directly** (not always via this wrapper) |

---

## 6. Gaps / open

1. Product / RTTI / Havok demangled name for vtbl+0x60 (keep inferred `ApplyPointImpulse`).
2. Exact type of second arg (`point` / wheel / hkVector4 world point).
3. Impulse layout f3 vs f4 at callers.
4. Full live caller list.
5. Runtime / bit-exact image diff.
6. Null-body crash policy (static: no check).

**Verdict:** **accept-with-gaps** — dual **CF + vtbl imm 0x60 + ret 8 + ready gate + sibling parity** sealed; package **not complete** (Havok name, point type, callers, runtime).
