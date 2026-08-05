# Function record: GlyphCache_PlacementCtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00754ee0` |
| **Canonical name** | `GlyphCache_PlacementCtor` |
| **Ghidra name** | `FUN_00754ee0` |
| **Address** | `0x00754ee0`–`0x00754FAB` exclusive (**203 B** / `0xCB`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | GlyphCache / font glyph texture host (Palantir) |
| **Completion status** | **Dual-sealed W35-H** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Classification** | worker |

## Alias

- Ghidra: `FUN_00754ee0`
- Reject scaffold: `Named_CalleeOf_Named_CalleeOf_Named_gfxFont_00754ee0` (parent-seed only)

## Purpose

Placement constructor for **GlyphCache** (`operator_new(0xB8)` host). Installs vtbl `PTR_FUN_00a9f584`, zeroes refcount and field blocks, default-constructs `basic_string` at `+0x18`, copies `DAT_00d1f01c`/`DAT_00d1f020` into two pairs of slots, and constructs nested **NestedHashBag** (0x30 sentinel) at `+0x44`.

## Signature (sealed)

```c
// stack(this*); RET 4; returns this in EAX
GlyphCache* GlyphCache_PlacementCtor(GlyphCache* self /*stack*/);
```

## Product evidence

- Vtbl-adjacent string @ `0x00a9f58C`: `"Failed to create texture for glyph cache"`.
- Complete dtor path uses GDI `DeleteObject` / `DeleteDC` on late slots.
- Sole factory caller `FUN_0073bc50` ties to font name + `"Arial"` fallback via `FUN_00754a10`.

## Layout (writes in this unit)

| Off | Init |
|-----|------|
| `+0x00` | vtbl `00a9f584` |
| `+0x04` | refcount `0` |
| `+0x08` | unwritten |
| `+0x0c..+0x14` | `0` |
| `+0x18` | `basic_string` default |
| `+0x38/+0x3c` | `DAT_00d1f01c` / `DAT_00d1f020` |
| `+0x40` | `0` |
| `+0x44` | NestedHashBag (W34-G) |
| `+0x70..+0x80` | `0` |
| `+0x84..+0x93` | unwritten gap |
| `+0x94..+0xac` | `0` (GDI slots later) |
| `+0xb0/+0xb4` | defaults again |
| sizeof | **`0xB8`** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00754ee0_FUN_00754ee0.md`
- Annotated: `docs/reconstruction/raw/aa_00754ee0_FUN_00754ee0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GlyphCache_PlacementCtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00754ee0.cpp`
- A: `docs/reconstruction/reviews/A_aa_00754ee0_GlyphCache_PlacementCtor.md`
- B: `docs/reconstruction/reviews/B_aa_00754ee0_GlyphCache_PlacementCtor.md`
- Scratch: `docs/reconstruction/tmp/a_00754ee0.md`

## Callers / callees

| Dir | Target |
|-----|--------|
| Caller (1) | `FUN_0073bc50` @ `0x0073bd02` |
| Callee | IAT `basic_string` ctor; `FUN_004438c0` NestedHashBag |

## Confidence

| Claim | Level |
|---|---|
| Stack this* / RET 4 / return this | **High** |
| Vtbl + product GlyphCache | **High** |
| Nested bag at +0x44 | **High** (W34-G) |
| Alloc 0xB8 | **High** (caller) |
| Default global meaning | **Low** |
| Unwritten slots / full dtor | Residual |

## Gaps

1. `DAT_00d1f01c` / `DAT_00d1f020` product meaning.
2. Unwritten `+0x08`, `+0x84..+0x93`.
3. Complete dtor / vtbl[2] duals unowned.
4. Runtime / bit-exact.

