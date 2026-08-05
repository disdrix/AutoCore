# Review A (reconstruction fidelity): `aa_004ff850` NDSpecialFX_ExpandVehicleHardpointSlots

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ff850` |
| **VA** | `0x004ff850`–`0x004ffe2e` (1502 B / `0x5DE`) |
| **Canonical name** | `NDSpecialFX_ExpandVehicleHardpointSlots` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004ff850` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W23-Q) |
| **Counterpart** | `reviews/B_aa_004ff850_NDSpecialFX_ExpandVehicleHardpointSlots.md` |
| **System** | `client-fx` / vehicle create-from-packet hardpoint expansion |
| **Verdict** | **accept-with-gaps** on CF / ABI / case table / strings / instantiate link; nested helpers + interior-this class **open** |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` + callers. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

During create-from-packet, expand **vehicle hardpoint child FX** from a dword type table on an NDSpecialFX-shaped template:

- Empty table → attach template + probe three host slots.
- Non-empty → switch on type id, snprintf named children, instantiate via sealed `NDSpecialFX_InstantiateFromTemplate`, optionally track for fail-notify, attach each child; finish with template attach.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_004ff850_FUN_004ff850.md` |
| Named record | `docs/reconstruction/functions/aa_004ff850_NDSpecialFX_ExpandVehicleHardpointSlots.md` |
| Raw | `docs/reconstruction/raw/aa_004ff850_FUN_004ff850.md` (+ W23-Q live seal) |
| Annotated | `docs/reconstruction/raw/aa_004ff850_FUN_004ff850.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDSpecialFX_ExpandVehicleHardpointSlots.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004ff850.cpp` |
| Live decompile | Ghidra `decompile_function` `0x004ff850` |
| Live body | `read_memory` entry 64 B + exit @ `0x004ffe20`; body end `004ffe2e` |
| Caller | `CVOG_CreateFromPacketDispatch` @ `0x00507000` only |
| Instantiate dual | `A_aa_004a0b90_NDSpecialFX_InstantiateFromTemplate` |

**Not performed:** Launcher, runtime golden, bit-exact image diff, dual of `FUN_005829d0` / `FUN_004b7030` / `FUN_00989270` (OWN residual).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **1502 B** / end `004ffe2e` | **Confirmed** | `get_function_by_address` |
| ABI **thiscall** + **`ret 0x0C`** | **Confirmed** | epilogue `C2 0C 00` |
| ECX = host; stack template / p3 / p4 | **Confirmed** | `mov edi,ecx`; `mov esi,[ebp+8]`; `mov ebx,[ebp+10]` |
| Type vector `+0x94/+0x98` dwords | **Confirmed** | entry loads + `sar …,2` |
| Empty path: attach + 3× `FUN_004b7030` | **Confirmed** | decomp ≡ raw |
| Case `0x0B/0x0F/0x10/0x11/0x15` + format strings | **Confirmed** | decomp immediates + string literals |
| Instantiate = `FUN_004a0b90` | **Confirmed** | call targets + dual |
| `param_4≠0` → FailMissionNotify track | **Confirmed** | five call sites |
| Name prefix `template+0xD5` | **High** | NDSpecialFX family dual |
| Role = vehicle HP FX expand on create | **High** | strings + sole CreateFromPacket caller |
| Interior-this class English | **Open** | offsets −0x330/−0x418/−0x628 |
| Nested helper semantics | Residual | not OWN duals this wave |
| Product / PDB name | **Open** | structural |
| Clean ≡ raw ≡ live CF | **High** | identity for sealed CF |
| Bit-for-bit / runtime | **Open** | deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Frame + large stack (5× 0x104 name bufs) | Yes |
| Null/empty type vector → empty path | Yes |
| Walk index / byteOff += 4 loop | Yes |
| Switch five HP types | Yes |
| WHEELSET count clamp `<3→4`, loop `i=1..count-1` | Yes |
| EXHAUST/BRAKES/LIGHTS/MELEE id ranges + `FUN_00989270` gate | Yes |
| Zero name / snprintf / instantiate / notify / attach | Yes |
| Terminal template `FUN_005829d0` | Yes |
| `ret 0x0C` | Yes |

### Recovered CF (summary)

```c
void Expand(void *thisHost, void *templateFx, uint32_t p3, int p4)
{
    if (null_or_empty(templateFx+0x94/0x98)) {
        FUN_005829d0(templateFx, p3, p4);
        for (i = 0; i < 3; i++)
            if (slot[i] = *(thisHost-0x330+4*i)) FUN_004b7030(slot[i], 0, 1, i);
        return;
    }
    for (index = 0; index < len; /* see early-continue cases */) {
        switch (type[index]) {
        case 0x0B: /* WHEELSET expand… */; continue;
        case 0x0F: /* EXHAUST 0x4BB..0x4BF */; continue;
        case 0x10: /* BRAKES  0x4C5..0x4CB */; break; // common tail
        case 0x11: /* LIGHTS  0x4CF..0x4D7 */; continue;
        case 0x15: /* MELEE   0x3E9..0x408 */; continue;
        }
        index++;
    }
    FUN_005829d0(templateFx, p3, p4);
}
```

---

## 5. Assembly contract (from `read_memory`)

### Entry

```
push ebp / mov ebp,esp / and esp,-8 / sub esp,0x544
push ebx / push esi
mov esi, [ebp+8]          ; templateFx
mov eax, [esi+0x94]
push edi / mov edi, ecx   ; thisHost
xor ecx, ecx
cmp eax, ecx
… jz empty_path
mov edx, [esi+0x98]
sub edx, eax / sar edx, 2
… jz empty_path
mov ebx, [ebp+10]         ; param_4
```

### Exit

```
pop edi / pop esi / pop ebx / mov esp,ebp / pop ebp / ret 0x0C
```

---

## 6. Gaps

1. Product/PDB English name.
2. Exact type of interior `thisHost` (negative field map).
3. Duals for `FUN_005829d0`, `FUN_004b7030`, `FUN_00989270`.
4. Runtime / bit-exact multi-child path.

---

## 7. Verdict

**accept-with-gaps** — CF, ABI, hardpoint case table, format strings, and instantiate linkage sealed against live decompile + entry/exit bytes. Nested attach/probe helpers and product symbol remain open.
