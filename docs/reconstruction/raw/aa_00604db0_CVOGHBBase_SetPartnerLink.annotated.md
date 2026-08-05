# Annotated (named): CVOGHBBase_SetPartnerLink

| Field | Value |
|---|---|
| Stable ID | `aa_00604db0` |
| VA | `0x00604db0` |
| Canonical | `CVOGHBBase_SetPartnerLink` |
| Date | 2026-07-29 W20-S |

Full annotated body: `docs/reconstruction/raw/aa_00604db0_FUN_00604db0.annotated.md`.

## Role (one-liner)

Conditionally store a partner heartbeat pointer at `this+0x24`, allowing clear (null) or link when the candidate partner’s owner (`+0x18`) differs from this owner; refuse overwrite when both non-null and same owner.
