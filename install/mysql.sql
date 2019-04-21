CREATE TABLE IF NOT EXISTS `log`
(
    `id`            BIGINT      UNSIGNED    AUTO_INCREMENT,
    `timestamp`     DATETIME    DEFAULT     CURRENT_TIMESTAMP,
    `priority`      SMALLINT    DEFAULT     0,
    `text`          TEXT        NOT NULL,

    PRIMARY KEY (`Id`)
)ENGINE = InnoDB AUTO_INCREMENT=1;
