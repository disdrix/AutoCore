# Review A (reconstruction fidelity): `aa_00467690` Phy_BoundingVolumeFactory_InvalidTag

| Field | Value |
|---|---|
| **Stable ID** | `aa_00467690` |
| **VA** | `0x00467690` |
| **Canonical name** | `Phy_BoundingVolumeFactory_InvalidTag` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00467690_Phy_BoundingVolumeFactory_InvalidTag.md` |
| **System** | `physics` / `phyBoundingVolumeFactory` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**FOURCC-tag bounding-volume factory** (not merely an error stub). Canonical name is string-driven from the null-tag log line; body is the **chunk-tag → BV instance** dispatcher used by bone unserialize / body-mass paths.

Signature (decompiler): `undefined4 * FUN_00467690(void *param_1)` — one stack arg = 32-bit tag dword.

Dispatch (big-endian FOURCC mnemonics; imm values match `('X'<<24)|…` style):

| Tag dword | FOURCC | Action | Size / twin |
|---|---|---|---|
| `0x42565350` | **BVSP** | `mov ecx,1` → `Phy_BoundingVolumeFactory_CreateFromTag` (`0x00467820`) | tag-1 sphere path (`0x18` inside CreateFromTag) |
| `0x42564258` | **BVBX** | `operator_new(0x20)` + `FUN_00467440` (EAX ctor) | box ctor; ≡ CreateFromTag case 2 |
| `0x42564350` | **BVCP** | `operator_new(0x28)` + `FUN_004674e0` | capsule ctor; ≡ CreateFromTag case 3 |
| `0x42565346` | **BVSF** | `operator_new(8)` + vtbl `PTR_FUN_00aa5c6c`, dword/float at `+4 = 0` | ≡ CreateFromTag case 4 |
| `0x42565753` | **BVWS** | `operator_new(0x100)` + `FUN_00467600(ptr)` | walkable surface; ≡ CreateFromTag case 5 |
| `0` | null | format `"Invalid tag [ %s ] for phyBoundingVolume"` via `FUN_0076cec0` + `vog_LogMessage(…phyBoundingVolumeFactory.h, 0x45, 3, …)` then null | error path only |
| other non-null | — | **silent** `return NULL` (no log) | |

OOM on any `operator_new` → `return NULL`.

Cross-type evidence (other VAs, used only as label evidence):

- `0x00981ac0` / `phyBVSphere.cpp` asserts tag `0x42565350` (BVSP)
- `0x00981d80` / `phyBVBox.cpp` asserts `0x42564258` (BVBX)
- `0x0098dbb0` / `phyBVCapsule.cpp` asserts `0x42564350` (BVCP)
- `0x0072c860` / `phyBVWalkableSurface.cpp` asserts `0x42565753` (BVWS)

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00467690_FUN_00467690.md` |
| Annotated | `docs/reconstruction/raw/aa_00467690_FUN_00467690.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phy_BoundingVolumeFactory_InvalidTag.cpp` |
| FUN scaffold | `docs/reconstruction/reconstructed-exact/FUN_00467690.cpp` |
| Function record | `docs/reconstruction/functions/aa_00467690_Phy_BoundingVolumeFactory_InvalidTag.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x00467690` (2026-07-29) — **≡ raw** |
| Body bytes | Ghidra `read_memory` @ `0x00467690` len 256 — CMP immediates `PSVB`/`XBVB`/`PCVB`/`FSVB`/`SWVB` LE encodings of BVSP/BVBX/BVCP/BVSF/BVWS |
| BVSP path | asm `B9 01 00 00 00` + `E8` → `CreateFromTag` with **ECX=1** |
| Sibling factory | `0x00467820` CreateFromTag numeric switch 1..5 (evidence only; not re-owned) |
| Callers (this VA) | `phyBoneSharedData_unserialize` @ `0x00997540` (2 call sites); `FUN_0095dc70` / body-massage path @ `0x0095dc70` (1 site) |
| Naming registry | `Phy_BoundingVolumeFactory_InvalidTag` ← string in `phyBoundingVolumeFactory.h` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role: FOURCC BV factory + null-tag log | **High** | full body; string + dispatch |
| Arg is tag dword (not object ptr) | **High** | compared to constants; stack load `8B 44 24 10` |
| BVSP → CreateFromTag(**1**) | **Confirmed** | decompile + `mov ecx,1` in body bytes |
| BVBX/BVCP/BVSF/BVWS alloc sizes 0x20/0x28/8/0x100 | **Confirmed** | body + raw |
| BVBX/BVCP/BVWS human types Box/Capsule/WalkableSurface | **High** | sibling unserialize string+tag asserts |
| BVSP = Sphere | **High** | `phyBVSphere.cpp` tag assert + CreateFromTag(1) sphere size 0x18 |
| BVSF human type name | **Medium** | FOURCC BVSF + type-4 twin only; no `phyBV*.cpp` string hit for SF |
| Null tag only path logs; other unknown tags silent null | **High** | explicit `if (param_1 == 0)` under non-BVWS arm |
| OOM → null | **High** | all new arms |
| clean ≡ raw ≡ live decompile CF | **High** | 2026-07-29 spot-check |
| Canonical name understates success paths | **High** | name from error string only; keep registry name |
| `FUN_00436190` string helper semantics | **Probable** | builds `basic_string` for `%s` in log; arg `0` with null tag |
| Runtime / bit-exact vs retail | **Open** | deferred project-wide |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Clean | Live |
|---|---|---|---|
| SEH frame setup (`LAB_009be484`) | Y | Y | Y |
| BVSP → CreateFromTag(1) return | Y | Y | Y |
| BVBX new 0x20 + ctor / OOM fallthrough | Y | Y | Y |
| BVCP new 0x28 + ctor | Y | Y | Y |
| BVSF new 8 + vtbl + zero +4 | Y | Y | Y |
| BVWS new 0x100 + `FUN_00467600` | Y | Y | Y |
| non-match: null → log @ line `0x45` + dtor string | Y | Y | Y |
| non-match: non-null → silent null | Y | Y | Y |
| terminal null return | Y | Y | Y |
| Invented / deleted arms | — | **None** | **None** |

### Recovered CF (authoritative)

```c
// phyBV* * Phy_BoundingVolumeFactory_InvalidTag(uint32_t fourccTag)
// Canonical name from error string; role = CreateFromFourCC

if (fourccTag == 0x42565350 /* BVSP */)
  return Phy_BoundingVolumeFactory_CreateFromTag(1);   // __fastcall ECX=1

if (fourccTag == 0x42564258 /* BVBX */) {
  void *p = operator_new(0x20);
  if (p) return BoxCtor_00467440(p);                   // EAX/this ctor
  return NULL;
}
if (fourccTag == 0x42564350 /* BVCP */) {
  void *p = operator_new(0x28);
  if (p) return CapsuleCtor_004674e0(p);
  return NULL;
}
if (fourccTag == 0x42565346 /* BVSF */) {
  void *p = operator_new(8);
  if (p) { *(p+4)=0; *p = &PTR_FUN_00aa5c6c; return p; }
  return NULL;
}
if (fourccTag == 0x42565753 /* BVWS */) {
  void *p = operator_new(0x100);
  if (p) return WalkableCtor_00467600(p);
  return NULL;
}
// unknown
if (fourccTag == 0) {
  // basic_string via FUN_00436190; format "Invalid tag [ %s ] for phyBoundingVolume"
  vog_LogMessage("..\\palantir/physics/phyBoundingVolumeFactory.h", 0x45, 3, msg);
}
return NULL;
```

---

## 5. Gaps / open

1. **BVSF** product type name (no matching `phyBV*.cpp` string in corpus; size-8 / `PTR_FUN_00aa5c6c` only).
2. Exact MSVC placement of `operator_new` result into EAX for `FUN_00467440` / `FUN_004674e0` (decompiler elides thiscall/`in_EAX` — behavior clear, calling glue Open detail).
3. `FUN_00436190` full contract (stringize path for null tag).
4. Runtime capture of bone-unserialize tags → returned vtbls.
5. Whether non-null unknown tags *should* log in source (binary: silent) — possible retail asymmetry vs CreateFromTag default which always logs.

**Verdict:** **accept-with-gaps** — FOURCC map, sizes, BVSP→CreateFromTag(1), null-only log, and clean≡raw≡live sealed for this VA.
